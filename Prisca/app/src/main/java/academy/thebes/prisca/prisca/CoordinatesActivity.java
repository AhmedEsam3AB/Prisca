package academy.thebes.prisca.prisca;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.util.UUID;

public class CoordinatesActivity extends AppCompatActivity {
    EditText xText;
    EditText yText;
    EditText zText;
    Button submit;
    ProgressBar prog;
    TextView sub;
    String xString;
    String yString;
    String zString;
    String address = null;
    BluetoothAdapter myBluetooth = null;
    BluetoothSocket btSocket = null;
    private boolean isBtConnected = false;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_coord);
        Intent newint = getIntent();
        address = newint.getStringExtra(PairedActivity.EXTRA_ADDRESS);
        submit = findViewById(R.id.button);
        xText = findViewById(R.id.x);
        yText = findViewById(R.id.y);
        zText = findViewById(R.id.z);
        prog = findViewById(R.id.prog);
        sub = findViewById(R.id.sub);
        new ConnectBT().execute();
        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                xString = xText.getText().toString();
                yString = yText.getText().toString();
                zString = zText.getText().toString();
                prog.setVisibility(View.VISIBLE);
                if(xString.isEmpty() || yString.isEmpty() || zString.isEmpty()){
                    Toast.makeText(CoordinatesActivity.this,"Please, Enter X,Y,Z Coordinates",Toast.LENGTH_SHORT).show();
                }else {
                    if (btSocket!=null)
                    {
                        try
                        {
                            byte[] bytesData =  (xString +"," + yString +"," + zString).getBytes();
                            String decodedData = new String(bytesData);
                            Log.v("Prisca",decodedData);

                            btSocket.getOutputStream().write(bytesData);
                        }
                        catch (IOException e)
                        {
                            msg("Error");
                        }
                    }
                    prog.setVisibility(View.GONE);
                    sub.setVisibility(View.VISIBLE);
                    final Handler handler = new Handler();
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            sub.setVisibility(View.GONE);
                            prog.setVisibility(View.INVISIBLE);

                        }
                    }, 2000);
                }
            }
        });


    }
    private void msg(String s) {
        Toast.makeText(getApplicationContext(), s, Toast.LENGTH_SHORT).show();
    }


    private class ConnectBT extends AsyncTask<Void, Void, Void>
    {
        private boolean ConnectSuccess = true;

        @Override
        protected void onPreExecute()
        {

        }

        @Override
        protected Void doInBackground(Void... devices)
        {
            try
            {
                if (btSocket == null || !isBtConnected)
                {
                    myBluetooth = BluetoothAdapter.getDefaultAdapter();
                    BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);
                    btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);
                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                    btSocket.connect();

                }
            }
            catch (IOException e)
            {
                ConnectSuccess = false;
            }
            return null;
        }

        @Override
        protected void onPostExecute(Void result)
        {
            super.onPostExecute(result);

            if (!ConnectSuccess) {
                msg("Connection Failed. Is it a SPP Bluetooth? Try again.");
                finish();
            } else {
                msg("Connected.");
                isBtConnected = true;
            }
        }
    }
}






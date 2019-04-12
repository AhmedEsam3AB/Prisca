package academy.thebes.prisca.prisca;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Handler;
import android.support.annotation.NonNull;
import android.support.annotation.RequiresApi;
import android.support.constraint.ConstraintLayout;
import android.support.design.widget.BottomSheetBehavior;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.util.UUID;

public class CoordinatesActivity extends AppCompatActivity {
    EditText xText;
    EditText yText;
    EditText zText;
    TextView newpos;
    TextView oldpos;
    TextView dis;
    Button submit;
    Button finish;
    String xString = "0";
    String yString = "0";
    String zString = "0";
    String xOld = "0";
    String yOld = "0";
    String zOld = "0";
    ConstraintLayout con;
    int x;
    int y;
    int z;
    int xDis;
    int yDis;
    int zDis;
    String address = null;
    BluetoothAdapter myBluetooth = null;
    BluetoothSocket btSocket = null;
    private boolean isBtConnected = false;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    FloatingActionButton fab;
    BottomSheetBehavior bottomSheetBehavior;


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
        fab = findViewById(R.id.fab);
        finish = findViewById(R.id.button2);
        con = findViewById(R.id.conLayout);
        newpos = findViewById(R.id.newpos);
        oldpos = findViewById(R.id.oldpos);
        dis = findViewById(R.id.dis);
        LinearLayout BottomSheet = (LinearLayout) findViewById(R.id.bottom_sheet);
        bottomSheetBehavior = BottomSheetBehavior.from(BottomSheet);
        bottomSheetBehavior.setHideable(false);
        bottomSheetBehavior.setPeekHeight(0);
        bottomSheetBehavior.setState(BottomSheetBehavior.STATE_HIDDEN);

        new ConnectBT().execute();
        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                xOld = xString;
                yOld = yString;
                zOld = zString;

                xString = xText.getText().toString();
                yString = yText.getText().toString();
                zString = zText.getText().toString();

                if (!(xString.isEmpty() || yString.isEmpty() || zString.isEmpty())) {
                    x = Integer.parseInt(xString);
                    y = Integer.parseInt(yString);
                    z = Integer.parseInt(zString);
                }
                if (xString.isEmpty() || yString.isEmpty() || zString.isEmpty()) {
                    Toast.makeText(CoordinatesActivity.this, "Please, Enter X,Y,Z Coordinates", Toast.LENGTH_SHORT).show();
                    xString = xOld;
                    yString = yOld;
                    zString = zOld;

                } else if (x > 30 || y > 30 || z > 50) {
                    Toast.makeText(CoordinatesActivity.this, "Out of 30x30x50cm range", Toast.LENGTH_SHORT).show();

                } else {
                    if (btSocket != null) {
                        if (xString.equals("0") && yString.equals("0") && zString.equals("0")) {
                            fab.setImageResource(R.drawable.mark);
                        } else {
                            fab.setImageResource(R.drawable.mark2);
                            fab.setClickable(true);
                        }
                        try {
                            byte[] bytesData = (xString + "," + yString + "." + zString + ";").getBytes();
                            String decodedData = new String(bytesData);
                            Log.v("Prisca", decodedData);

                            btSocket.getOutputStream().write(bytesData);
                        } catch (IOException e) {
                            msg("Error");
                        }
                    }
                    bottomsheet();
                }


            }
        });

        fab.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                if (btSocket != null) {
                    fab.setImageResource(R.drawable.mark);
                    fab.setClickable(false);
                    xOld = xString;
                    yOld = yString;
                    zOld = zString;

                    xText.setText("0");
                    yText.setText("0");
                    zText.setText("0");
                    try {
                        byte[] bytesData = ("0" + "," + "0" + "." + "0" + ";").getBytes();
                        String decodedData = new String(bytesData);
                        Log.v("Prisca", decodedData);

                        btSocket.getOutputStream().write(bytesData);
                    } catch (IOException e) {
                        msg("Error");
                    }
                }
                bottomsheet();

            }
        });
    }


    private void bottomsheet() {
        con.setBackgroundColor(Color.parseColor("#99000000"));
        xString = xText.getText().toString();
        yString = yText.getText().toString();
        zString = zText.getText().toString();
        oldpos.setText("(" + " " + xOld + " " + "," + " " + yOld + " " + "," + " " + zOld + " " + ")");
        newpos.setText("(" + " " + xString + " " + "," + " " + yString + " " + "," + " " + zString + " " + ")");
        xDis = Integer.valueOf(xString) - Integer.valueOf(xOld);
        yDis = Integer.valueOf(yString) - Integer.valueOf(yOld);
        zDis = Integer.valueOf(zString) - Integer.valueOf(zOld);
        dis.setText("(" + " " + xDis + " " + "," + " " + yDis + " " + "," + " " + zDis + " " + ")");
        xText.setFocusable(false);
        yText.setFocusable(false);
        zText.setFocusable(false);
        bottomSheetBehavior.setState(BottomSheetBehavior.STATE_EXPANDED);
        bottomSheetBehavior.setBottomSheetCallback(new BottomSheetBehavior.BottomSheetCallback() {
            @Override
            public void onStateChanged(@NonNull View bottomSheet, int newState) {
                if (newState == BottomSheetBehavior.STATE_DRAGGING) {
                    bottomSheetBehavior.setState(BottomSheetBehavior.STATE_EXPANDED);
                }
            }

            @Override
            public void onSlide(@NonNull View bottomSheet, float slideOffset) {
            }
        });

        finish.setClickable(true);
        finish.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                con.setBackgroundColor(Color.parseColor("#ffffff"));
                xText.setFocusableInTouchMode(true);
                yText.setFocusableInTouchMode(true);
                zText.setFocusableInTouchMode(true);
            }
        });

    }


    private void msg(String s) {
        Toast.makeText(getApplicationContext(), s, Toast.LENGTH_SHORT).show();
    }


    private class ConnectBT extends AsyncTask<Void, Void, Void> {
        private boolean ConnectSuccess = true;

        @Override
        protected void onPreExecute() {

        }

        @Override
        protected Void doInBackground(Void... devices) {
            try {
                if (btSocket == null || !isBtConnected) {
                    myBluetooth = BluetoothAdapter.getDefaultAdapter();
                    BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);
                    btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);
                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                    btSocket.connect();

                }
            } catch (IOException e) {
                ConnectSuccess = false;
            }
            return null;
        }

        @Override
        protected void onPostExecute(Void result) {
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







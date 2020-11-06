package com.example.smartcontroller;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.google.firebase.auth.FirebaseAuth;

public class Ac_Controller extends AppCompatActivity {

    Button mup,mback,mdown;
    TextView mtxt;
    FirebaseAuth fAuth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ac__controller);

        mup = findViewById(R.id.up);
        mback = findViewById(R.id.back);
        mdown = findViewById(R.id.down);
        mtxt = findViewById(R.id.value);
        fAuth =FirebaseAuth.getInstance();


        mback.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                startActivity(new Intent(getApplicationContext(),MainActivity.class));

            }
        });
    }
}
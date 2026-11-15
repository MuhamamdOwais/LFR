// Pin Definitions for Motor A
const int in1 = 7;  // Motor A forward
const int in2 = 8;  // Motor A backward
const int ena = 9;// Motor A speed control (PWM pin)

// Pin Definitions for Motor B
const int in3 = 10;  // Motor B forward
const int in4 = 11; // Motor B backward
const int enb = 12; // Motor B speed control (PWM pin)

// Pin Definitions for Sensors
const int sensor1 = 2;  // Far left
const int sensor2 = 3;  // Left
const int sensor3 = 4;  // Center
const int sensor4 = 5;  // Right
const int sensor5 = 6;  // Far right

// Motor speed
const int motorSpeed = 255; // Base speed of the motors (adjust as needed)

void setup() {
    // Motor Pins
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(ena, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enb, OUTPUT);

    // Sensor Pins
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);
    pinMode(sensor5, INPUT);

    // Start Serial for Debugging
    Serial.begin(9600);
}

void loop() {
    // Read IR sensors
    int s1 = digitalRead(sensor1); // Far left
    int s2 = digitalRead(sensor2); // Left
    int s3 = digitalRead(sensor3); // Center
    int s4 = digitalRead(sensor4); // Right
    int s5 = digitalRead(sensor5); // Far right

    // Debug output
    Serial.print(s1);
    Serial.print(s2);
    Serial.print(s3);
    Serial.print(s4);
    Serial.println(s5);
             if( s3 == LOW && s4 == LOW && s5 == LOW ){ 
        sharpRight();
    } 

    else if (s3 == LOW ) { 
        moveForward();
    }            else  if( s3 == LOW && s4 == LOW && s5 == LOW ){ 
        sharpRight();
    } 
    else if (s3 == LOW && s4 == LOW) { 
        sharpRight();
    } 

     else if (s4 == LOW) {
        sharpRight();
    }
    else if (s4 == LOW && s5 == LOW) {
        sharpRight();
    } else if (s3 == LOW && s2 == LOW) { 
        sharpLeft();
    }
    else if (s2 == LOW) { 
        sharpLeft();
    } 
    else if (s1 == LOW && s2 == LOW) { 
        sharpLeft();
    } 
            else  if(s1 == LOW && s2 == LOW && s3 == LOW  ){ 
        sharpLeft();
    }
    
    else if (s1 == LOW ) {
         sharpLeft();
    }
    else  if(s1 == LOW && s2 == LOW && s3 == LOW && s4 == LOW && s5 == LOW  ){ 
        stopMotors();
    }
        else  if(s1 == LOW && s2 == LOW && s3 == LOW  ){ 
        sharpLeft();
    }
        else  if( s3 == LOW && s4 == LOW && s5 == LOW ){ 
        sharpRight();
    }
}



// Movement Functions
void moveForward() {
    digitalWrite(in1, HIGH);  // Left motor forward
    digitalWrite(in2, LOW);
    analogWrite(ena, motorSpeed);  // Set left motor speed

    digitalWrite(in3, HIGH);  // Right motor forward
    digitalWrite(in4, LOW);
    analogWrite(enb, motorSpeed);  // Set right motor speed
}

void slightLeft() {
    digitalWrite(in1, LOW);  // Left motor stops (slows)
    digitalWrite(in2, LOW);
    analogWrite(ena, motorSpeed / 2);  // Half speed on left motor

    digitalWrite(in3, HIGH);  // Right motor forward
    digitalWrite(in4, LOW);
    analogWrite(enb, motorSpeed);  // Full speed on right motor
}


void slightRight() {
    digitalWrite(in1, HIGH);  // Left motor forward
    digitalWrite(in2, LOW);
    analogWrite(ena, motorSpeed);  // Full speed on left motor

    digitalWrite(in3, LOW);  // Right motor stops (slows)
    digitalWrite(in4, LOW);
    analogWrite(enb, motorSpeed / 2);  // Half speed on right motor
}

void sharpRight() {
    digitalWrite(in1, HIGH);  // Left motor forward
    digitalWrite(in2, LOW);
    analogWrite(ena, motorSpeed);  // Full speed forward on left motor

    digitalWrite(in3, LOW);   // Right motor backward
    digitalWrite(in4, HIGH);  
    analogWrite(enb, motorSpeed);  // Full speed backward on right motor
}


void sharpLeft() {
    digitalWrite(in1, LOW);   // Left motor backward
    digitalWrite(in2, HIGH);  
    analogWrite(ena, motorSpeed);  // Full speed backward on left motor

    digitalWrite(in3, HIGH);  // Right motor forward
    digitalWrite(in4, LOW);   
    analogWrite(enb, motorSpeed);  // Full speed forward on right motor
}




void stopMotors() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(ena, 0); // Stop left motor

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enb, 0); // Stop right motor
}

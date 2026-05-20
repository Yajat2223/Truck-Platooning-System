#include <SoftwareSerial.h>

// Bluetooth RX, TX
SoftwareSerial bt(10, 11);

// Motor Driver Pins
int IN1 = 2;   // Right Motor
int IN2 = 3;
int IN3 = 4;   // Left Motor
int IN4 = 5;

int ENA = 9;   // Right Motor Speed
int ENB = 6;   // Left Motor Speed

char command;

// Motor Speed (0 - 255)
int speedVal = 170;

void setup() {

  bt.begin(9600);
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  stopCar();
}

void loop() {

  if (bt.available()) {

    command = bt.read();
    Serial.println(command);

    switch (command) {

      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      case 'S':
        stopCar();
        break;
    }
  }
}

// FORWARD
void forward() {

  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// BACKWARD
void backward() {

  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// LEFT TURN
void left() {

  // Right motor ON
  analogWrite(ENA, speedVal);

  // Left motor OFF
  analogWrite(ENB, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// RIGHT TURN
void right() {

  // Right motor OFF
  analogWrite(ENA, 0);

  // Left motor ON
  analogWrite(ENB, speedVal);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// STOP
void stopCar() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

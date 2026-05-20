// ---------------- MOTOR PINS ----------------

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int ENA = 9;
int ENB = 6;

// ---------------- ULTRASONIC SENSOR ----------------

int trig = 7;
int echo = 8;

// ---------------- IR SENSORS ----------------

int leftIR = 10;
int rightIR = 11;

// ---------------- VARIABLES ----------------

long duration;
int distance;

void setup() {

  Serial.begin(9600);

  // Motor Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Enable Pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Ultrasonic Pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // IR Sensor Pins
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  // Motor Speed
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  stopCar();
}

void loop() {

  // ---------- MEASURE DISTANCE ----------

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  // ---------- READ IR SENSORS ----------

  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  // ---------- DEBUGGING ----------

  Serial.print("Distance: ");
  Serial.println(distance);

  // ---------- DISTANCE CONTROL ----------

  if (distance < 10) {

    // Too close to leader
    backward();
  }

  else if (distance > 20) {

    // Leader is far away

    if (left == 0 && right == 1) {

      turnLeft();
    }

    else if (left == 1 && right == 0) {

      turnRight();
    }

    else {

      forward();
    }
  }

  else {

    // Ideal distance
    stopCar();
  }

  delay(40);
}

// ---------------- FORWARD ----------------

void forward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ---------------- BACKWARD ----------------

void backward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// ---------------- TURN LEFT ----------------

void turnLeft() {

  // Right motor ON
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Left motor OFF
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ---------------- TURN RIGHT ----------------

void turnRight() {

  // Right motor OFF
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Left motor ON
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ---------------- STOP ----------------

void stopCar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

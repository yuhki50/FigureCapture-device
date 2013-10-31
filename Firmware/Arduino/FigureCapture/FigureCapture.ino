// Figure Capture
// by yuhki50 <http://www.yuhki50.com>

#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 200;

Servo *servo0;
Servo *servo1;
Stepper *stepper0;
Stepper *stepper1;

int pos = 0;

void setup() {
  // ステータスLED
  pinMode(13, OUTPUT);

  // サーボモーターを初期化
  servo0 = new Servo();
  servo0->attach(2);
  servo0->write(90);

  servo1 = new Servo();
  servo1->attach(3);
  servo1->write(90);

  // ステッピングモーターを初期化
  stepper0 = new Stepper(stepsPerRevolution, 5, 6, 7, 8);
  stepper1 = new Stepper(stepsPerRevolution, 9, 10, 11, 12);

  delay(5000);

  // シリアルポートを初期化
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {

  } else {

  }
}

/*
const int stepsPerRevolution = 200;


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution/100);
  }
}
*/


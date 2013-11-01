// Figure Capture
// by yuhki50 <http://www.yuhki50.com>

#include <Servo.h>
#include <Stepper.h>
#include <math.h>
#include <config.h>

//const int stepsPerRevolution = 200;


Servo *servo0;
Servo *servo1;
Stepper *stepper0;
Stepper *stepper1;


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
  stepper0 = new Stepper(96, 5, 6, 7, 8);
  stepper1 = new Stepper(96, 9, 10, 11, 12);

  // シリアルポートを初期化
  Serial.begin(9600);
  Serial.println("finish setup!");
  stepper0->setSpeed(1);
}

int speed = 1;

void loop() {
  if (Serial.available() > 0) {
    byte value = Serial.read();
    if (value == 'a') {
      speed++;
    } else if (value == 's') {
      speed--;
    }
    Serial.println(speed);
    stepper0->setSpeed(abs(speed) + 1);
  }
  stepper0->step(speed > 0 ? 1 : -1);




  if (Serial.available() > 0) {
    byte value = Serial.read();

    if (value == NULL) {

    } else {

    }
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


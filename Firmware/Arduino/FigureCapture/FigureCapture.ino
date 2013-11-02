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
  stepper0->setSpeed(200);
  stepper1 = new Stepper(96, 9, 10, 11, 12);
  stepper1->setSpeed(10);

  // シリアルポートを初期化
  Serial.begin(9600);
  Serial.println("finish setup!");
}

int speed = 1;
int rotate = 90;

byte value;

void loop() {
  /*
   * servo0 : a[direction][angle]  ex a+180, a-090
   * servo1 : b[direction][angle]  ex b+180, b-090
   * stepper0 : c[direction][step]  ex c+010, c-010
   * stepper1 : d[direction][step]  ex d+010, d-010
   */
  if (Serial.available() >= 5) {
    byte type = Serial.read();
    char direction = Serial.read() == '-' ? -1 : 1;
    int value = (Serial.read() - 48) * 100;
    value += (Serial.read() - 48) * 10;
    value += (Serial.read() - 48) * 1;

    if (type == 'a') {
      servo0->write(90 + (value * direction));

    } else if (type == 'b') {
      servo1->write(90 + (value * direction));

    } else if (type == 'c') {
      Serial.println("c through");
      stepper0->step(value * direction);

    } else if (type == 'd') {
      Serial.println("d through");
      //stepper1->step(value * direction);
      stepper1->step(value);

    } 

    Serial.write(type);
    Serial.println();
    Serial.print(direction, DEC);
    Serial.println();
    Serial.println(value, DEC);

    Serial.println("---");

    Serial.flush();
  }
}


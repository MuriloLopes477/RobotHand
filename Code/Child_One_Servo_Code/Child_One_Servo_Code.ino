#include <Servo.h>
#include <Wire.h>

# define I2C_CHILD1_ADDRESS 11

#define MAX_SERVO_RANGE 160
#define MED_SERVO_RANGE 80
#define MIN_SERVO_RANGE 0
#define SERVO_RANGE4 30
#define SERVO_RANGE5 130
#define SERVO_RANGE6 42

Servo middleLeft; //3
Servo middleRight; //5

void setup() {
  //Begins wire only in child1 address
  Wire.begin(I2C_CHILD1_ADDRESS);
  Serial.begin(9600);

  Wire.onReceive(receiveParentData);
  
  //sets servo motors pins
  middleLeft.attach(3);
  middleRight.attach(5);
}

void loop() {
    
}

void receiveParentData(int bytesNum) {
  Serial.print("Received Data:");
  int servo_info = Wire.read();
  int servo_id = String(servo_info).substring(0,1).toInt();
  int servo_pos = String(servo_info).substring(1).toInt();
  Serial.println(servo_id);
  // int servo_pos = Wire.read();
  moveServo(servo_id, servo_pos);
}


void moveServo(int servo_id, int servo_pos) {
  if(servo_pos == 1) {
    if (servo_id == 1) {
      middleLeft.write(MAX_SERVO_RANGE);
    } else if (servo_id == 2) {
      middleRight.write(MAX_SERVO_RANGE);
    } else if (servo_id == 3) {
    } else if (servo_id == 4) {
    } else if (servo_id == 5) {
    } else {

    }
  } else if(servo_pos == 2) {
    if (servo_id == 1) {
      middleLeft.write(MED_SERVO_RANGE);
    } else if (servo_id == 2) {
      middleRight.write(MED_SERVO_RANGE);
    } else if (servo_id == 3) {
    } else if (servo_id == 4) {
    } else if (servo_id == 5) {
    } else {

    }
  } else if(servo_pos == 3) {
    if (servo_id == 1) {
      middleLeft.write(MIN_SERVO_RANGE);
    } else if (servo_id == 2) {
      middleRight.write(MIN_SERVO_RANGE);
    } else if (servo_id == 3) {
    } else if (servo_id == 4) {
    } else if (servo_id == 5) {
    } else {

    }
  } else if(servo_pos == 4) {
    if (servo_id == 1) {
      middleLeft.write(SERVO_RANGE4);
    } else if (servo_id == 2) {
      middleRight.write(SERVO_RANGE4);
    } else if (servo_id == 3) {
    } else if (servo_id == 4) {
    } else if (servo_id == 5) {
    } else {

    }
  } else if(servo_pos == 5) {
    if (servo_id == 1) {
      middleLeft.write(SERVO_RANGE5);
    } else if (servo_id == 2) {
      middleRight.write(SERVO_RANGE5);
    } else if (servo_id == 3) {
    } else if (servo_id == 4) {
    } else if (servo_id == 5) {
    } else {

    }
  }  else if(servo_pos == 6) {
    if (servo_id == 1) {
      middleLeft.write(SERVO_RANGE6);
    } else if (servo_id == 2) {
      middleRight.write(SERVO_RANGE6);
    } else if (servo_id == 3) {
    } else if (servo_id == 4) {
    } else if (servo_id == 5) {
    } else {

    }
  } 
}
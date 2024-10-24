#include <Servo.h>
#include <Wire.h>

# define I2C_CHILD2_ADDRESS 12

#define MAX_SERVO_RANGE 160
#define MED_SERVO_RANGE 80
#define MIN_SERVO_RANGE 0
#define SERVO_RANGE4 30
#define SERVO_RANGE5 130
#define SERVO_RANGE6 42

Servo wristLeft;//3
Servo wristRight;//5
Servo thumbRight;//6
Servo indexLeft;//9
Servo indexRight;//10

void setup() {
  //Begins wire only in child1 address
  Wire.begin(I2C_CHILD2_ADDRESS);
  Serial.begin(9600);

  //Sets receiving protocols
  Wire.onReceive(receiveParentData);
  
  //sets servo motors pins
  wristLeft.attach(3);
  wristRight.attach(5);
  thumbRight.attach(6);
  indexLeft.attach(9);
  indexRight.attach(10);
  
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
      wristRight.write(MAX_SERVO_RANGE);
    } else if (servo_id == 2) {
      wristLeft.write(MAX_SERVO_RANGE);
    } else if (servo_id == 3) {
      thumbRight.write(MAX_SERVO_RANGE);
    } else if (servo_id == 4) {
      indexLeft.write(MAX_SERVO_RANGE);
    } else if (servo_id == 5) {
      indexRight.write(MAX_SERVO_RANGE);
    } else {

    }
  } else if(servo_pos == 2) {
    if (servo_id == 1) {
      wristRight.write(MED_SERVO_RANGE);
    } else if (servo_id == 2) {
      wristLeft.write(MED_SERVO_RANGE);
    } else if (servo_id == 3) {
      thumbRight.write(MED_SERVO_RANGE);
    } else if (servo_id == 4) {
      indexLeft.write(MED_SERVO_RANGE);
    } else if (servo_id == 5) {
      indexRight.write(MED_SERVO_RANGE);
    } else {

    }
  } else if(servo_pos == 3) {
    if (servo_id == 1) {
      wristRight.write(MIN_SERVO_RANGE);
    } else if (servo_id == 2) {
      wristLeft.write(MIN_SERVO_RANGE);
    } else if (servo_id == 3) {
      thumbRight.write(MIN_SERVO_RANGE);
    } else if (servo_id == 4) {
      indexLeft.write(MIN_SERVO_RANGE);
    } else if (servo_id == 5) {
      indexRight.write(MIN_SERVO_RANGE);
    } else {

    }
  } else if(servo_pos == 4) {
    if (servo_id == 1) {
      wristRight.write(SERVO_RANGE4);
    } else if (servo_id == 2) {
      wristLeft.write(SERVO_RANGE4);
    } else if (servo_id == 3) {
      thumbRight.write(SERVO_RANGE4);
    } else if (servo_id == 4) {
      indexLeft.write(SERVO_RANGE4);
    } else if (servo_id == 5) {
      indexRight.write(SERVO_RANGE4);
    } else {

    }
  } else if(servo_pos == 5) {
    if (servo_id == 1) {
      wristRight.write(SERVO_RANGE5);
    } else if (servo_id == 2) {
      wristLeft.write(SERVO_RANGE5);
    } else if (servo_id == 3) {
      thumbRight.write(SERVO_RANGE5);
    } else if (servo_id == 4) {
      indexLeft.write(SERVO_RANGE5);
    } else if (servo_id == 5) {
      indexRight.write(SERVO_RANGE5);
    } else {

    }
  }  else if(servo_pos == 6) {
    if (servo_id == 1) {
      wristRight.write(SERVO_RANGE6);
    } else if (servo_id == 2) {
      wristLeft.write(SERVO_RANGE6);
    } else if (servo_id == 3) {
      thumbRight.write(SERVO_RANGE6);
    } else if (servo_id == 4) {
      indexLeft.write(SERVO_RANGE6);
    } else if (servo_id == 5) {
      indexRight.write(SERVO_RANGE6);
    } else {

    }
  } 
}

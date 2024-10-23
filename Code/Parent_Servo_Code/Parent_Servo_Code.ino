#include <Servo.h>
#include <Wire.h>

# define I2C_CHILD1_ADDRESS 11
# define I2C_CHILD2_ADDRESS 12

#define MAX_SERVO_RANGE 160;

Servo pinkyDown;  
Servo ringDown;
Servo indexDown;
Servo middleDown;
Servo thumbDown;

//Children servos:
// 1 -> wristRight
// 2 -> wristLeft
// 3 -> thumbRight
// 4 -> indexLeft
// 5 -> indexRight

void setup() {
  //begins wire connection
  Wire.begin(); 
  Serial.begin(9600);


  // attaches and sets start position for servo objects
  // pinkyDown.attach(5); 
  // ringDown.attach(3);
  // indexDown.attach(6); 
  // middleDown.attach(9);

}

void loop() {
  // sendServoDataToChild(I2C_CHILD1_ADDRESS, 11);
  // sendServoDataToChild(I2C_CHILD1_ADDRESS, 23);
  // delay(100);
}

void sendServoDataToChild(int child_id, int servo_info) {
  Wire.beginTransmission(child_id);
  Wire.write(servo_info);
  // Wire.write(servo_pos);
  Wire.endTransmission();
}

void waveHand() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 11);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 21);
  delay(1350);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 13);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 22);
  delay(1350);
}
void moveThumbRight() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 33);
  }
void moveThumbLeft() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 31);
  }
void moveIndexForward() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 45);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 53);
}
void relaxIndex() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 43);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 51);
}
void moveIndexRight() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 44);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 54);
}
void moveIndexLeft() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 45);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 56);
}
void moveIndexStiff() {
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 42);
  sendServoDataToChild(I2C_CHILD2_ADDRESS, 54);
}


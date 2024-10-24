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

void moveMiddleRight() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 12);
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 26);
}
void moveMiddleStiff() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 11);
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 26);
}
void moveMiddleLeft() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 18);
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 26);
}
void relaxMiddle() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 13);
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 28);
}

void moveRingStiff() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 36);//top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 44);//bottom
}
void moveRingRight() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 32);//top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 43);//bottom
}
void moveRingLeft() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 34);//top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 46);//bottom
}

void movePinkyForward() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 61); //top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 55); //bottom
}

void movePinkyLeft() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 62); //top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 55); //bottom
}

void movePinkyRight() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 63); //top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 54); //bottom
}
void movePinkyStiff() {
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 64); //top
  sendServoDataToChild(I2C_CHILD1_ADDRESS, 58); //bottom
}

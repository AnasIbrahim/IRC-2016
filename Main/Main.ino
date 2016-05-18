//IRC 2016 - 35-bit team Automatic ROBOT program

#include <math.h>
#include <Servo.h>

//Motors Speeds - max PWM is Half of 255
byte PWMRunning = 110; //110 for play ground
byte oneMotorSpeedDifference = 90; //determine speed of a motor when that should be slower than the other while tracking line //90 for playground
byte rotateSpeed = 65; //65 for playground
byte rotateSpeedUndominantMotor = 0;
byte rotateSpeedDominantMotor = 0; 
byte turnDelayPower = 800;
byte turnDelayAssure = 100;

Servo catchServo;
Servo armServo;

//TODO: set new pins values - for Motors & Sensors
//TODO: delete additional sensors
int RightMotorForward = 4;
int RightMotorBack  = 5;
int LeftMotorForward = 2;
int LeftMotorBack = 3;

//ultrasonic
int trigPin = 11;
int echoPin = 12;

//TODO: sensors not used connect them to the same pin as the sensor Zthat should have a similar reading (ex. FND & BND - LND & RND)
int FR_LT = 22 ; // Front-Right line tracking sensor //
int FL_LT = 23 ; // Front-Left line tracking sensor //
int BR_LT = 24 ; // Back-Right line tracking sensor //
int BL_LT = 25 ; // Back-Left line tracking sensor //
int FND = 26 ; // Front Node Detector //
int BND = 26 ; // Front Back Detector //
int LND  = 27 ; // Front Left Detector //
int RND  = 27 ; // Front Right Detector // //not used - changed from 30
int center  = 28 ; // center of Node Detector //
//TODO: delete those sensors if they were not in the design
//int RightRotation = 32;
//int LeftRotation = 32;

//current position of the robot
byte CPX = 0; //current position of X
byte CPY = 0; //current position of Y
char Look = 'F'; //Direction of the robot head (robot Arm) - intiallized with forward


//TODO: check if ther is additional track
//TODO: change size of the arrays to a arrays to dynamic (dynamic memory allocation)
//boolean **track1 = createArray(15,2); //Track1: from start position to block1
//boolean **track2 = createArray(15,2); //Track2: from block1 to bridge start
//boolean **track3 = createArray(15,2); //Track3: from end of bridge to common point
//boolean **track4 = createArray(15,2); //Track4: from point after common point to finish


byte block1X = 0, block1Y = 0, block2X = 0, block2Y = 0;
    
void setup()
{
  pinMode( LeftMotorForward ,OUTPUT);
  pinMode( RightMotorForward ,OUTPUT);
  pinMode( LeftMotorBack ,OUTPUT);
  pinMode( RightMotorBack ,OUTPUT);

  pinMode( trigPin,OUTPUT);
  pinMode( echoPin,INPUT);
  
  pinMode( FR_LT ,INPUT);
  pinMode( FL_LT ,INPUT);
  pinMode( BR_LT ,INPUT);
  pinMode( BL_LT ,INPUT);
  pinMode( center  ,INPUT);
  pinMode( FND  ,INPUT);
  pinMode( BND  ,INPUT);
  pinMode( RND  ,INPUT);
  pinMode( LND  ,INPUT);
//  pinMode(RightRotation, INPUT);
//  pinMode(LeftRotation, INPUT);
  
  //TODO: set new pins values - for Arm Servo Motors
  armServo.attach(8);
  catchServo.attach(10);

  Serial.begin(9600);
}

void loop()
{
//COMPETITION CODE
//lifting ARM
servoMove(armServo, 170);

Run('F');
Turn('R', 1);
Run('F');
Turn('L', 1);
Run('F');


catchBlock();
//TODO: get back (BACK LINE TRACKING)
Run('B');
Run('F');

Turn('R', 1);
Run('F');
Run('F');

//TODO Special Track and putting block
Run('F');
Turn('L', 1);

PWMRunning = 160;
Run('F');
PWMRunning = 110;

Turn('L', 1);

PWMRunning = 55;
Run('F');
PWMRunning = 110;

Turn('R', 1);
Run('F');
//forwardOnly();
delay(1000);

//waiting to move
delay(45000);
Turn('L', 1);
Run('F');
Run('F');
Run('F');

stopMotors();
while(1){};

//NEXT is not tested
//specialTrack();
//Turn('R', 1);
//Run('F');
//forwardOnly();
//delay(500);
//stopMotors();
////------------------------------------------------------------

//digitalWrite(LeftMotorForward, HIGH);

//analogWrite(RightMotorForward,PWMRunning);
//analogWrite(LeftMotorForward,PWMRunning);
//analogWrite(RightMotorBack,0);
//analogWrite(LeftMotorBack,0);
//delay(3000);
//turnRight();
//delay(3000);
//turnLeft();
//delay(3000);
//stopMotors();

//goToNextPoint(1, 0);
//goToNextPoint(1, 0);

//armServo.write(170);
//delay(2000);
//catchServo.write(180);
//delay(2000);
//armServo.write(70);
//delay(2000);
//catchServo.write(122);
//delay(2000);
//armServo.write(160);
//delay(2000);
//armServo.write(70);
//delay(2000);

//servoMove(armServo, 170);
//delay(2000);

//catchBlock();

//Serial.print(Distance());
//Serial.print("\n");
//delay(1000);

//Run('B');
//Run('F');
//Turn('R', 1);

//checkAllSensors();

//while(1){};
}
//===================================================

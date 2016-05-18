//Control Of Robot Arm
//TODO check this code indepdently 

//TODO: set new servo degree values for the new arm
byte openAngleCatch = 180;
byte closingAngleCatch = 122;
byte upAngleArm = 170;
byte downAngleArm = 70;

void catchBlock()
{
  servoMove(armServo, upAngleArm);
  servoMove(catchServo, openAngleCatch);
  servoMove(armServo, 90);

  //getting closer to block
  int trials = 0;
  while (trials < 3)
  {
    int dist = Distance();
    if ( dist <= 8 && dist != 0)
    {
      trials++;
      delay(10);
    }
    else
    {
      runningForward();
    }
  }
  stopMotors();

  servoMove(armServo, downAngleArm);
  servoMove(catchServo, closingAngleCatch);
  servoMove(armServo, upAngleArm);
    //catchServo.write(openAngleCatch);
    //armServo.write(downAngleArm);
    //catchServo.write(closingAngleCatch);
    //armServo.write(upAngleArm);
}

void releaseBlock()
{
  servoMove(armServo, downAngleArm);
  servoMove(catchServo, openAngleCatch);
  servoMove(armServo, upAngleArm);
    //armServo.write(downAngleArm);
    //catchServo.write(openAngleCatch);
    //armServo.write(upAngleArm);
}

void servoMove(Servo &servo, byte finalAngle)
//this function is used to slow the motion of of Servo Motors - takes 1.8 second to move from 0 deg to 180 deg
//TODO: this function needs verification on:
//    1- that servo motor is passed correctly (maybe a refrence need to be used)
//    2- calling read() function without any calls to write first (this maybe can solved by intializing the arm to a predetermined position
//    3- refresh the servo every 50ms: should refresh be called or not - also check if it's was made right
//    4- another way of using refresh function was used on arduino servo library documentation
//TODO: another way this method can be implemented is to extend the servo class - check if this can be made
{
  byte angle = servo.read();
//  Serial.print("current angle= ");
//  Serial.print(angle);
//  Serial.print("\n");
//  
//  Serial.print("final angle= ");
//  Serial.print(finalAngle);
//  Serial.print("\n");
  
  //checking which angle is bigger - swapping if finalAngle is bigger
  if (finalAngle < angle) { //byte tempAngle = finalAngle; finalAngle = angle; angle = tempAngle; Serial.print("swapping\n");}
    for (; angle >= finalAngle; angle--) {
      //Serial.print("moving -ve\n");
      servo.write(angle);
      delay(20);
      //TODO: should refresh be called or not
        //SoftwareServo::refresh();
    }
  }
  else { // (angle < finalAngle)
    for (; angle <= finalAngle; angle++) {
      //Serial.print("moving +ve\n");
      servo.write(angle);
      delay(20);
      //TODO: should refresh be called or not
        //SoftwareServo::refresh();
    }
  }

  delay(2000);
}

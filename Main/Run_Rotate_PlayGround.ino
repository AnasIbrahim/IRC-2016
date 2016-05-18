//this is the first layer of motor control
  //this code is responsible for directly moving the motors
  // generally if moves the motor to a specific grid intersection (maybe after of before grid intersection
  //    and rotate robot without any knowledge of robots position of Direction (Look variable)

//Functions that can be called from outside the file:
//    1- Run
//    2- RunBeforeIntersection
//    other functions must be called with complete caution when dealing with special tracks
//TODO: if FR_LT and FL_LT both are on black the robot will continue to make the last signal applied to both motors - may need to be fixed

//TODO:braking in stopMotors() function may be changed to brake slower (without short circuiting motors)

void Run(char R_Dir)
//run and stop after lines intersection
{
  RunStopBeforeIntersection(R_Dir);
  
  //stopping after intersection for both forward and backward
  if      (R_Dir == 'F') { stoppingAfterIntersectionForward();  }
  else if (R_Dir == 'B') { stoppingAfterIntersectionBackward(); }
  
  //motors already shuted down
  stopMotors();
}

void RunStopBeforeIntersection(char R_Dir)
{
  if(R_Dir == 'F')
  {
    //running forward
    while(1)
    {
      runningForward();
      //breaking at intersection
      if (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW)
      {
        break;
        
      }
    }
  }
  
  if(R_Dir == 'B')
  {
    //running Backward
    while(1)
    {
      //breaking at intersection
      runningBackward();
      if(digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW )
      {
        break;
      }
    }
  }
   
  //shutting down all motors
  stopMotors(); 
}

void stoppingAfterIntersectionForward()
{
  while(1)
  {
    runningForward();
    if (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== HIGH  && digitalRead(LND)== HIGH )
    {
      break;
    }
  }
  //shutting down all motors
  stopMotors(); 
}

void stoppingAfterIntersectionBackward()
{
  while(1)
  {
    runningBackward();
    if(digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== HIGH  && digitalRead(LND)== HIGH )
    {
      break;
    }
  }
  //shutting down all motors
  stopMotors(); 
}

void runningForward()
//this function can work even if the front line tracking don't have a line that the function will use the back line tracking sensors
{
  if(digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW ) 
  {
    analogWrite(RightMotorForward,PWMRunning);
    analogWrite(LeftMotorForward,PWMRunning);
    analogWrite(RightMotorBack,0);
    analogWrite(LeftMotorBack,0);
    //incase of using digital pins
      //digitalWrite(RightMotorForward, HIGH);
      //digitalWrite(LeftMotorForward, HIGH);
      //digitalWrite(RightMotorBack, LOW);
      //digitalWrite(LeftMotorBack, LOW);
  }
  //robot drifted to right
  else if (digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == HIGH)
  {
    analogWrite(RightMotorForward,PWMRunning);
    analogWrite(LeftMotorForward,PWMRunning - oneMotorSpeedDifference);
    analogWrite(RightMotorBack,0);
    analogWrite(LeftMotorBack,0);
    //incase of using digital pins
      //digitalWrite(RightMotorForward, LOW);
      //digitalWrite(LeftMotorForward, HIGH);
      //digitalWrite(RightMotorBack, LOW);
      //digitalWrite(LeftMotorBack, LOW)
  }
  //robot drifted to left
  else if (digitalRead(FR_LT) == HIGH && digitalRead(FL_LT) == LOW)
  {
    analogWrite(RightMotorForward,PWMRunning - oneMotorSpeedDifference);
    analogWrite(LeftMotorForward,PWMRunning);
    analogWrite(RightMotorBack,0);
    analogWrite(LeftMotorBack,0);
    //incase of using digital pins
      //digitalWrite(RightMotorForward, HIGH);
      //digitalWrite(LeftMotorForward, LOW);
      //digitalWrite(RightMotorBack, LOW);
      //digitalWrite(LeftMotorBack, LOW);
  }
  //if front line tracking sensors failed then use back line tracking sensors
  if (digitalRead(FR_LT) == HIGH && digitalRead(FL_LT) == HIGH)
  {
    if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == LOW)
    {
      analogWrite(RightMotorForward,PWMRunning);
      analogWrite(LeftMotorForward,PWMRunning);
      analogWrite(RightMotorBack,0);
      analogWrite(LeftMotorBack,0);
      //incase of using digital pins
        //digitalWrite(RightMotorForward, HIGH);
        //digitalWrite(LeftMotorForward, HIGH);
        //digitalWrite(RightMotorBack, LOW);
        //digitalWrite(LeftMotorBack, LOW);
    }
    //robot drifted to right
    else if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == HIGH)
    {
      analogWrite(RightMotorForward,PWMRunning - oneMotorSpeedDifference);
      analogWrite(LeftMotorForward,PWMRunning);
      analogWrite(RightMotorBack,0);
      analogWrite(LeftMotorBack,0);
      //incase of using digital pins
        //digitalWrite(RightMotorForward, LOW);
        //digitalWrite(LeftMotorForward, HIGH);
        //digitalWrite(RightMotorBack, LOW);
        //digitalWrite(LeftMotorBack, LOW)
    }
    //robot drifted to left
    else if (digitalRead(BR_LT) == HIGH && digitalRead(BL_LT) == LOW)
    {
      analogWrite(RightMotorForward,PWMRunning);
      analogWrite(LeftMotorForward,PWMRunning - oneMotorSpeedDifference);
      analogWrite(RightMotorBack,0);
      analogWrite(LeftMotorBack,0);
      //incase of using digital pins
        //digitalWrite(RightMotorForward, HIGH);
        //digitalWrite(LeftMotorForward, LOW);
        //digitalWrite(RightMotorBack, LOW);
        //digitalWrite(LeftMotorBack, LOW);
    }
  }
}

void runningBackward()
{
  if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == LOW )
  {
    analogWrite(RightMotorForward,0);
    analogWrite(LeftMotorForward,0);
    analogWrite(RightMotorBack,PWMRunning);
    analogWrite(LeftMotorBack,PWMRunning);
    //incase of using digital pins
      //digitalWrite(RightMotorForward, LOW);
      //digitalWrite(LeftMotorForward, LOW);
      //digitalWrite(RightMotorBack, HIGH);
      //digitalWrite(LeftMotorBack, HIGH);
  }
  else if (digitalRead(BR_LT) == HIGH && digitalRead(BL_LT) == LOW )
  {
    analogWrite(RightMotorForward,0);
    analogWrite(LeftMotorForward,0);
    analogWrite(RightMotorBack,PWMRunning);
    analogWrite(LeftMotorBack,PWMRunning - oneMotorSpeedDifference);
    //incase of using digital pins
      //digitalWrite(RightMotorForward, LOW);
      //digitalWrite(LeftMotorForward, LOW);
      //digitalWrite(RightMotorBack, HIGH);
      //digitalWrite(LeftMotorBack, LOW);
  }  
  else if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == HIGH )
  {
    analogWrite(RightMotorForward,0);
    analogWrite(LeftMotorForward,0);
    analogWrite(RightMotorBack,PWMRunning - oneMotorSpeedDifference);
    analogWrite(LeftMotorBack,PWMRunning);
    //incase of using digital pins
      //digitalWrite(RightMotorForward, LOW);
      //digitalWrite(LeftMotorForward, LOW);
      //digitalWrite(RightMotorBack, LOW);
      //digitalWrite(LeftMotorBack, HIGH);
  }
}
//===================================================
void Turn (char Dir , byte times)
{
  int x = 0 ;
  if (Dir == 'R')
  {
    while (x < times)
    {
      //getting some power to turn
      turnRightHIGH(); 
      delay(turnDelayPower);
      //getting out of current line
      while (digitalRead(FR_LT) == LOW || digitalRead(FL_LT) == LOW) { turnRight(); }
      //making sure current line was passed
      turnRight(); 
      delay(turnDelayAssure);
      //turning till next line is reached
      while(1)
      {
        turnRight();
        //old condition //if(digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW)
        if(digitalRead(FR_LT) == LOW)
        {
          x++;
          break;
        }
        //TODO:what is that !!!!!!
          //if (RightRotation == HIGH) {analogWrite(RightMotorBack, rotateSpeed);}
          //if (LeftRotation == HIGH) {analogWrite(LeftMotorForward, rotateSpeed);}
          //if (RightRotation == LOW && LeftRotation == LOW) { crossingAnyIntersection(); x++; break;}
      }
    }
  }
  else if (Dir == 'L')
  {
    while (x < times)
    {
      //getting some power to turn
      turnLeftHIGH(); 
      delay(turnDelayPower);
      //getting out of current line
      while (digitalRead(FR_LT) == LOW || digitalRead(FL_LT) == LOW) { turnLeft(); }
      //making sure current line was passed
      turnLeft(); 
      delay(turnDelayAssure);
      //turning till next line is reached
      while(1)
      {
        turnLeft();
        //old condition //if( digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW)
        if( digitalRead(FL_LT) == LOW)
        {
          x++;
          break;
        }
        //TODO:what is that !!!!!!
          //if (RightRotation == HIGH) {analogWrite(RightMotorForward, rotateSpeed);}
          //if (LeftRotation == HIGH) {analogWrite(LeftMotorBack, rotateSpeed);}
          //if (RightRotation == LOW && LeftRotation == LOW) { crossingAnyIntersection(); x++; break;}
      }
    }
  }
  stopMotors();
}

void turnRight()
{
  analogWrite(LeftMotorForward, rotateSpeed + rotateSpeedDominantMotor);
  analogWrite(RightMotorBack, rotateSpeed - rotateSpeedUndominantMotor);
  
  analogWrite(RightMotorForward, 0);
  analogWrite(LeftMotorBack, 0);
  //incase of using digital pins
    //digitalWrite(LeftMotorForward, HIGH);
    //digitalWrite(RightMotorBack, HIGH);
}

void turnLeft()
{
  analogWrite(RightMotorForward, rotateSpeed + rotateSpeedDominantMotor);
  analogWrite(LeftMotorBack, rotateSpeed - rotateSpeedUndominantMotor);

  analogWrite(LeftMotorForward, 0);
  analogWrite(RightMotorBack, 0);
  //incase of using digital pins
    //digitalWrite(RightMotorForward, HIGH);
    //digitalWrite(LeftMotorBack, HIGH);
}

void turnRightHIGH()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBack, LOW);
  digitalWrite(LeftMotorBack, HIGH);
}

void turnLeftHIGH()
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBack, HIGH);
  digitalWrite(LeftMotorBack, LOW);
}

void stopMotors()
{
//    analogWrite(RightMotorForward,0);
//    analogWrite(LeftMotorForward,0);
//    analogWrite(RightMotorBack,0);
//    analogWrite(LeftMotorBack,0);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBack, HIGH);
  digitalWrite(RightMotorBack, HIGH);
  
  delay(200);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBack, LOW);
  digitalWrite(RightMotorBack, LOW);
}

void runForaWhile()
{
  for (int count = 0; count <= 20; count++)
  runningForward();
  delay(50);
}

void crossingAnyIntersection()
{ 
  boolean previousLND, currentLND;
  boolean previousRND, currentRND;
  
  if (digitalRead(LND)== HIGH) {previousLND = HIGH;} else {previousLND = LOW;}
  if (digitalRead(RND)== HIGH) {previousRND = HIGH;} else {previousRND = LOW;}
  
  if (digitalRead(LND)== HIGH) {currentLND = HIGH;} else {currentLND = LOW;}
  if (digitalRead(RND)== HIGH) {currentRND = HIGH;} else {currentRND = LOW;}
  
  while(previousLND == currentLND && previousRND == currentRND)
  {
    runningForward();
      
    if (digitalRead(LND)== HIGH) {currentLND = HIGH;} else {currentLND = LOW;}
    if (digitalRead(RND)== HIGH) {currentRND = HIGH;} else {currentRND = LOW;}
  }
  
  stopMotors();
}
//===================================================
void runningForwardHIGH()
{
  if(digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW ) 
  {
      digitalWrite(RightMotorForward, HIGH);
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(RightMotorBack, LOW);
      digitalWrite(LeftMotorBack, LOW);
  }
  //robot drifted to right
  else if (digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == HIGH)
  {
      digitalWrite(RightMotorForward, LOW);
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(RightMotorBack, LOW);
      digitalWrite(LeftMotorBack, LOW);
  }
  //robot drifted to left
  else if (digitalRead(FR_LT) == HIGH && digitalRead(FL_LT) == LOW)
  {
      digitalWrite(RightMotorForward, HIGH);
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(RightMotorBack, LOW);
      digitalWrite(LeftMotorBack, LOW);
  }
}

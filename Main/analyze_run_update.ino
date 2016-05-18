//this is the second layer of motor control
  //it simply moves the robot from a point to an adjacent one and also updates the robot position and direction (look)

//Functions that can be called from outside the file:
//    Only goToNextPoint: it's also responsible of moving the robot to the passed point

void goToNextPoint(int NPX, int NPY)
//determine the look of the robot after moving and move the robot to the point passed
{
  char N_Look;
  if(CPX > NPX)
  {
    N_Look = 'B';
  }
  if(CPX < NPX)
  {
    N_Look = 'F';
  }
  if(CPY > NPY)
  {
    N_Look = 'L';
  }
  if(CPY < NPY)
  {
    N_Look = 'R';
  }       
 analyse_to_run( Look,  N_Look);
 CPX  = NPX;
 CPY  = NPY;
 Look = N_Look;
}

int analyse_to_run(char C_Look, char N_Look)
{
  if (C_Look == 'F' && N_Look == 'F')
  {
    Run('F');
  }
  if (C_Look == 'F' && N_Look == 'R')
  {
    Turn('R',1);
    Run('F');
  }
  if (C_Look == 'F' && N_Look == 'L')
  {
    Turn('L',1);
    Run('F');

  }        
  if (C_Look == 'F' && N_Look == 'B')
  {
    Turn('R',2);
    Run('F');
  }          
//---------------------------------------------------      
  if (C_Look == 'B' && N_Look == 'B')
  {
    Run('F');
  }
  if (C_Look == 'B' && N_Look == 'R')
  {
    Turn('L',1);
    Run('F');
  }
  if (C_Look == 'B' && N_Look == 'L')
  {
    Turn('R',1);
    Run('F');
  }        
  if (C_Look == 'B' && N_Look == 'F')
  {
    Turn('R',2);
    Run('F');
  }          
//---------------------------------------------------      
  if (C_Look == 'R' && N_Look == 'R')
  {
    Run('F');
  }
  if (C_Look == 'R' && N_Look == 'B')
  {
    Turn('R',1);
    Run('F');
  }
  if (C_Look == 'R' && N_Look == 'F')
  {
    Turn('L',1);
    Run('F');
  }        
  if (C_Look == 'R' && N_Look == 'L')
  {
    Turn('R',2);
    Run('F');
  }          
//---------------------------------------------------      
  if (C_Look == 'L' && N_Look == 'L')
  {
    Run('F');
  }
  if (C_Look == 'L' && N_Look == 'F')
  {
    Turn('R',1);
    Run('F');
  }
  if (C_Look == 'L' && N_Look == 'B')
  {
    Turn('L',1);
    Run('F');
  }        
  if (C_Look == 'L' && N_Look == 'R')
  {
    Turn('R',2);
    Run('F');
  }     
}
//---------------------------------------------

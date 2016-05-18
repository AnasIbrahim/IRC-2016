//this is the third layer of motor control
  //Input of this code:
    // 1- the current position of the robot (the global field)
    // 2- the data of node and block places scanned in the dry run
    // 3- the final position to move the robot to it (it can be any point on the grid

  //Output of this code: is an array of point - these points are the track the robot will take to reach it's destination
    //the robot doesn't move at all in this code - it only determine the tracks
    //this way could help detemining all the tracks directly after the dry run - saving time of the competition

//TODO: add saving tracks to EEPROM and determine tracks before starting

boolean** determineTrack(byte CPX, byte CPY, byte NPX ,byte NPY)
{
  
}

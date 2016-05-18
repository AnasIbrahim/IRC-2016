//used to check if senors is connected or not and determine it's state (white or Black)
//TODO: while checking sensors connection make sure that White color returns LOW and Black returns HIGH

bool checkSensor(int sensor)
{
    if (digitalRead(sensor) == HIGH)        { Serial.print("b"); }
    else /*(digitalRead(sensor) == HIGH) */ { Serial.print("w"); } //condition not needed
    Serial.print(" ");
}

void checkAllSensors()
{
  checkSensor(FR_LT);
  checkSensor(FL_LT);
  Serial.print("    ");
  checkSensor(FND);
  checkSensor(BND);
  Serial.print("    ");
  checkSensor(center);
  Serial.print("    ");
  checkSensor(LND);
  checkSensor(RND);
  Serial.print("    ");
  checkSensor(BR_LT);
  checkSensor(BL_LT);
//  checkSensor(LeftRotation);
//  checkSensor(RightRotation);
  Serial.print("\n");
  delay(1000);
}

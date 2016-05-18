int Distance()
{
   int duration, distance;
   digitalWrite(trigPin, HIGH);
   delay(100);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration/2) / 29.1;

  Serial.print(distance); Serial.print("\n");
  return distance;
}

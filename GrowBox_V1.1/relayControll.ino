void relaySwitch()
{
  
  //delay(1000);
  if (DHT.temperature >= 25) digitalWrite(13, LOW);
  else digitalWrite(13, HIGH);
  
  if (DHT.humidity >= 40) digitalWrite(12, LOW);
  else digitalWrite(12, HIGH);
//  
//  if ((int)humidity >= 40) digitalWrite(4, LOW);
//  else digitalWrite(4, HIGH);
  
  if (moisureData < 700) digitalWrite(4, LOW);
  else digitalWrite(4, HIGH);
  
  if (hours == 8 && minutes == 0) digitalWrite(9, LOW);
  else if (hours == 20 && minutes == 0)digitalWrite(9, HIGH);
  
  if (hc06Data == "11on")     digitalWrite(2, LOW);
  else if (hc06Data == "11off")     digitalWrite(2, HIGH);

}

void dataToDigit (char data[])
{
  Serial.print("datatoDigit\n");
  //Serial.println(sizeof(data));
  //char data [sizeof(VegetationData)];
  if(data[1]=='V')
  {
    data = VegetationData;
  }
  else if (data[1]=='Y')
  {
    data = FloweringData;
  }
  
  
  
  char cutedCharData [3];
  //Serial.println(sizeof(VegetationData));
  int index = 0;
  short counter = 0;
  int digitalData = 0;
  for(int i = 3; i < 40; )
  {
    //Serial.println(data[i]);
    
      while( data[i] >= '0' && data[i]<='9')
     {
        
        cutedCharData[index] = data[i];
        index++;
        i++;   

                
     }
     if(data[i]== ' '|| data[i] == ')')
      {
        index = 0;
        counter++;

      }
     
     i++; 
     if(counter == 1)
     {
      digitalData = atoi(cutedCharData);
      Serial.print("temp min: ");
      Serial.println(digitalData);
      tempMin = atoi(cutedCharData);

     }
     if(counter == 2)
     {
      digitalData = atoi(cutedCharData);
      Serial.print("temp max: ");
      Serial.println(digitalData);
      tempMax = atoi(cutedCharData);

     }
     if(counter == 3)
     {
      digitalData = atoi(cutedCharData); 
      Serial.print("hum min: ");
      Serial.println(digitalData);
      humMin = atoi(cutedCharData);

     }
     if(counter == 4)
     {
      digitalData = atoi(cutedCharData);
      Serial.print("hum max: ");
      Serial.println(digitalData);
      humMax = atoi(cutedCharData);

     }
     if(counter == 5)
     {
      digitalData = atoi(cutedCharData);
      Serial.print("light on time: ");
      Serial.println(digitalData);
      lightOn = atoi(cutedCharData);

     }
     if(counter == 6)
     {
      digitalData = atoi(cutedCharData);
      Serial.print("light off time: ");
      Serial.println(digitalData);
      lightOff = atoi(cutedCharData);

     }
     if(counter == 7)
     {
      digitalData = atoi(cutedCharData);
      Serial.print("duration ");
      Serial.println(digitalData);
      duration = atoi(cutedCharData);
      break;

     }
     
  }
//  Serial.print("counter value");
//  Serial.println(counter);
  
}

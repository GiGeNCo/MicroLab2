void checkData(String data)
{
  char cData[40];
  data.toCharArray(cData,40);
  Serial.println(cData);  
  if(data == "status")
  {
    hc06Data = "";
    sendRTCDataToBluetooth();
    //sendDHT11DataToBluetooth();
    printSomeData();
    sendDHT11DataToBluetooth();
  }
  else if(data == "current")
  {
    hc06Data = "";
    hc06.write("Data is not imported");
    hc06.write("\n");
    Serial.println("No input");    
  }
  else if(cData[0]=='(' && cData[1] == 'V' )
  {
    //VegetationData = cData;
    data.toCharArray(VegetationData,40);
    //Serial.println(sizeof(VegetationData));
    
    vegetation(VegetationData);
    //hc06.write("vegetation data is received");
  }
  else if(cData[0]= '(' && cData[1] == 'Y' )
  {    
    data.toCharArray(FloweringData,40);
    flowering(FloweringData);
    //hc06.write("flowering data is received ");
    
  }
  
}

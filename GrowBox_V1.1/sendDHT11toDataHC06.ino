void sendDHT11DataToBluetooth()
{
//    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
//    {
//      Serial.print("Read DHT11 failed, err = "); Serial.println(err); delay(100);
//      return;
//    }
    strTemp=String(DHT.temperature);
    strHum = String(DHT.humidity);
    strTemp.toCharArray(cTemp,3);    
    strHum.toCharArray(cHum,3); 
    strMoisure = String(moisureData);
    strMoisure.toCharArray(cMoisure,3);

    hc06.write("ტემპერატურა: "); hc06.write(cTemp); hc06.write("°C");
    hc06.write("\n"); 
    hc06.write("ტენიანობა: "); hc06.write(cHum); hc06.write("%");
    hc06.write("\n");
    hc06.write("ნიადაგის ტენიანობა: "); hc06.write(cMoisure); hc06.write("%");
  
}

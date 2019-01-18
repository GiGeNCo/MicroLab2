void sendRTCDataToBluetooth()
{   
    
    strMinute=String(minutes);
    strHour = String(hours);
    strSecond = String(seconds);  
    strHour.toCharArray(cHour,3);
    strMinute.toCharArray(cMinute,3); 
    strSecond.toCharArray(cSecond,3);
    hc06.write("მიმდინარე დრო");
    hc06.write(": ");
    hc06.write(cHour);
    hc06.write(":");
    hc06.write(cMinute);
    hc06.write(":");    
    hc06.write(cSecond);
    hc06.write("\n");
}

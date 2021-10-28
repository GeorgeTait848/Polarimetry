// C++ code
//

  

int totalSensorValue = 0;
int loopCounter = 1;


void setup() {
  
  
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
}

void loop() {
 
 
   
 int sensorValue = analogRead(A0);
  
 totalSensorValue += sensorValue;
  

  
  if (loopCounter == 10) {
   
    float averageSensorValue = totalSensorValue / 10.0;
      
    float averageVoltage = averageSensorValue * (5.0/1024.0);
    
    Serial.println(averageVoltage);
    
    totalSensorValue = 0;
    
    loopCounter = 0;
    
  }
  

  
  loopCounter ++;
  
  delay(100);
  
  
}

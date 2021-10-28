// C++ code
//
/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

int pos = 0;
int totalSensorValue = 0;
int numberOfLoops = 10; 

Servo servo_9;




void setup()
{
  servo_9.attach(9, 500, 2500);
  pinMode(A0, INPUT);
  Serial.begin(9600);

  Serial.print("Angle of Max Voltage (deg)");
  Serial.println( "  \t Max Voltage (V)");

}





float getOutputVoltage(int numberOfLoops) {

  int i = 0;
  for (i = 0; i<= numberOfLoops; i ++) {
     
     int sensorValue = analogRead(A0);
     
     totalSensorValue += sensorValue; 
    
  }


   float averageSensorValue = float(totalSensorValue) / float(numberOfLoops);

   float averageVoltage = averageSensorValue * (5.0/1024.0);

   totalSensorValue = 0;

   return averageVoltage;
   
}




void loop() {
  
  float maxVoltage = 0.0;
  int posOfMaxVoltage = 0;
  
  for (pos = 0; pos <= 180; pos += 1) {
    servo_9.write(pos);
   
    delay(5);

   float voltageOfCurrentPos = getOutputVoltage(numberOfLoops);

    if (voltageOfCurrentPos > maxVoltage) {

      maxVoltage = voltageOfCurrentPos;
      posOfMaxVoltage = pos;
      
    }
    delay(5);
    
  }

  Serial.print(posOfMaxVoltage);

  Serial.print("\t");
  Serial.println(maxVoltage);

    delay(100);
    
}

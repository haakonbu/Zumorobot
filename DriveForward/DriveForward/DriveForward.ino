#include <PLab_ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>


#define QTR_THRESHOLD 1500 // this might need to be tuned for different
 //lighting conditions, surfaces, etc
#define SPEED 300 //0isstopped, 400 is full speed
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
boolean direction = LOW; // Drives motors forward, HIGH drives reverse
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);

void setup()
{
 button.waitForButton();
}
void loop()
{
 sensors.read(sensor_values);

 //Check if border has been detected by any of the two sensors at each side
 if ((sensor_values[0] < QTR_THRESHOLD))
 {
 motors.setSpeeds(400,-400); //Stop,
 delay(250);
 // Change to opposite direction
 motors.setSpeeds(SPEED, SPEED); // Move away in opposite direction
 delay(100); // Use enough time to be off border before reading sensors again

 }
 else if(sensor_values[5] < QTR_THRESHOLD){
  motors.setSpeeds(-400,400);
  
  delay(250);
   motors.setSpeeds(SPEED, SPEED); // Move away in opposite direction
  delay(100);
 }
 else{
 motors.setSpeeds(SPEED, SPEED);
 }
}

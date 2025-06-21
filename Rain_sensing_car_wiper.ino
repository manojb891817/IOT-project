#include <Servo.h>

Servo myservo;
Servo myservo1; 

int pos = 0; 
int sensorValue = 0;


void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo1.attach(10); 
}

void loop() 
{
  sensorValue = analogRead(A0);  // Read the moisture level from the sensor
  Serial.println(sensorValue);  // Display the sensor value on Serial Monitor
  
  if (sensorValue > 650) {  // Wettest condition (most rain)
    // Perform wiping action with quick speed
    for (pos = 0; pos <= 120; pos += 1) { 
      myservo.write(pos);  
      myservo1.write(pos);             
      delay(3);  // Small delay for smooth movement
    }

    for (pos = 120; pos >= 0; pos -= 1) {
      myservo.write(pos);  
      myservo1.write(pos);             
      delay(3);  // Small delay for smooth movement
    }

    delay(100);  // Short rest after fast wipe

  } else if (sensorValue > 600 && sensorValue <= 650) {  // Moderate rain
    // Perform wiping action at moderate speed
    for (pos = 0; pos <= 120; pos += 1) { 
      myservo.write(pos);  
      myservo1.write(pos);             
      delay(5);  // Moderate delay for slower wiping
    }

    for (pos = 120; pos >= 0; pos -= 1) {
      myservo.write(pos);  
      myservo1.write(pos);             
      delay(5);  // Moderate delay for slower wiping
    }

    delay(1000);  // Rest after moderate wipe

  } else if (sensorValue > 460 && sensorValue <= 600) {  // Light rain
    // Perform wiping action at slow speed
    for (pos = 0; pos <= 120; pos += 1) { 
      myservo.write(pos); 
      myservo1.write(pos);              
      delay(8);  // Larger delay for slow wiping
    }

    for (pos = 120; pos >= 0; pos -= 1) {
      myservo.write(pos);  
      myservo1.write(pos);             
      delay(8);  // Larger delay for slow wiping
    }

    delay(2000);  // Longer rest after slow wipe

  } else {  // Dry conditions (no rain)
    myservo.write(0);  // Resting position for both servos (wipers off)
    myservo1.write(0);
    delay(1000);  // Longer rest as no wiping is needed
  }
}

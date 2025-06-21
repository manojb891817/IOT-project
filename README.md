# Rain Sensing Automatic Car Wiper System Using Arduino


📝 Project Overview:
This project is a smart windshield wiper system for vehicles. It automatically detects the intensity of rain using a moisture (rain) sensor and controls two servo motors to simulate the wiping action. The wiper speed changes dynamically based on how much it is raining (light, moderate, or heavy). It eliminates the need for manually operating wipers, improving safety and convenience for drivers.

⚙️ Components Used:
Component	Quantity	Description
Arduino Uno / Nano	1	Microcontroller to control the system
Servo Motors (SG90)	2	Actuators for wiper movement
Rain or Soil Moisture Sensor	1	Detects rainfall intensity
Jumper Wires	–	For connections
Breadboard	1	For prototyping connections
USB Cable	1	To connect Arduino to the computer
Power Supply (Battery/USB)	1	For running the Arduino


🔌 Working Principle:
The sensor reads the moisture level (analog value) from the environment.

This value is passed to the Arduino's analog pin A0.

Based on the sensor value:

If it's very high (e.g. >650) → It means heavy rain, so the wipers move fast.

If it's moderate (600–650) → It’s moderate rain, so the wipers move at medium speed.

If it’s between 460 and 600 → It’s light rain, so the wipers move slowly.

If below 460 → No rain detected, so the wipers stay at rest.

Two servo motors are used to simulate a pair of wipers moving synchronously in both directions.



🧠 Code Logic Summary:
analogRead(A0) → Gets sensor value.

Based on value:

Heavy rain → delay(3) per servo step → Fast movement.

Medium rain → delay(5) → Medium speed.

Light rain → delay(8) → Slow movement.

Dry → Set both servos to 0 degrees (rest).

The wiping motion is a sweep from 0 to 120 degrees and back.



📊 Sample Output:
Rain Condition	Sensor Value Range	Servo Speed	Delay Time
Heavy Rain	> 650	Very Fast	3 ms
Moderate Rain	600–650	Medium	5 ms
Light Rain	460–600	Slow	8 ms
Dry	< 460	Wipers Resting	


🎯 Applications:
Smart vehicles for automated wiper control.

Can be integrated into IoT-based car systems.

Useful in driver-assistance systems for real-time weather response.


📈 Advantages:
Hands-free operation improves driver focus and safety.

Adaptive speed reduces wear and saves energy.

Can be extended to real car wipers with motor drivers.

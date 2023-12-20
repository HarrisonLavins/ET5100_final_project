# ET5100 Final Project
A final project mechatronics project in fulfillment of the requirements for ET 5100 Fundamentals of Mechatronics and Industrial Applications at Wayne State University for Fall 2023.

## Summary
A front-wheel drive mecanum robot with keyless-start RFID fob.



## Video Results

Final system test, with feline actor present in scene: [https://youtu.be/Nl-UMUDqDqc](https://youtu.be/Nl-UMUDqDqc)

Software integration test: [https://youtu.be/BEJVBEg0dmk](https://youtu.be/BEJVBEg0dmk)

System integration test: [https://youtu.be/gco-cSQoEw0](https://youtu.be/gco-cSQoEw0)


## System Requirements

### Minimum requirements:
- The system shall include at least one sensor.
- The system shall include at least one actuator (motors).
- The system shall include at least one control unit or microcontroller (Arduino).
- The system shall possess a keyless entry RFID sensor which will start the vehicle and initiate motion.

### Objective requirements (Stretch Goals)
- The system shall allow an operator to wirelessly teleoperate the vehicle indoors from a distance of no less than 10m.
- The system shall be able to operate on battery power alone for a period of no less than 30 minutes.
- The system shall have a top forward drive speed of no less than 0.5 m/s.
- The system shall be able to pivot turn 180 degrees.
- The system shall be able to travel directly sideways to the left and right.
- The system shall be able to detect when a frontal collision is imminant and engage an automatic emergency braking (AEB) collision mitigation action.

## Physical Architecture
Physical architecture is depicted below:



## Vetronics Architecture
Initial vetronics design sketches are outlined below:


## Software Architecture
The entrypoint and main executable for the Arduino platform microcontroller unit is [keyFobStartFWD.ino](https://github.com/HarrisonLavins/ET5100_final_project/blob/main/arduino/platformController/keyFobStartFWD/keyFobStartFWD.ino)

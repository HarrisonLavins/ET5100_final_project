# ET5100 Final Project
A final project mechatronics project in fulfillment of the requirements for ET 5100 Fundamentals of Mechatronics and Industrial Applications at Wayne State University for Fall 2023.

## Summary
A front-wheel drive mecanum robot with keyless-start RFID fob.

<img title="Front Wheel Drive Mecanum Robot" alt="Front Wheel Drive Mecanum Robot" src="https://raw.githubusercontent.com/HarrisonLavins/ET5100_final_project/main/screenshots/robot.jpeg" style="width: 500px; height: auto;">


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

<img title="Front Wheel Drive Mecanum Robot" alt="Front Wheel Drive Mecanum Robot" src="https://raw.githubusercontent.com/HarrisonLavins/ET5100_final_project/main/screenshots/robot.jpeg" style="width: 500px; height: auto;">

<img title="Front Wheel Drive Mecanum Robot Architecture" alt="Front Wheel Drive Mecanum Robot Architecture" src="https://raw.githubusercontent.com/HarrisonLavins/ET5100_final_project/main/screenshots/upside_down.jpeg" style="width: 500px; height: auto;">



## Vetronics Architecture
Initial vetronics design sketches are outlined below:

<img title="Vetronics Design" alt="Vetronics Design" src="https://raw.githubusercontent.com/HarrisonLavins/ET5100_final_project/main/screenshots/vetronics_diagram.JPG" style="width: 500px; height: auto;">

These initial vetronics architecture designs were sketched out on paper during the design period, and in order to future-proof the design to support additional software features and sensor upgrades at a later time, were developed to support an additional Raspberry Pi 4 compute node. Designing the power distribution in this way to support additional computational resources provided by the Raspberry Pi would allow for the stretch goal to be able to wirelessly teleoperate the robot from a distance using Bluetooth, connect camera modules to steam video over wifi, connect additional sensors, and more.


## Software Architecture
The entrypoint and main executable for the Arduino platform microcontroller unit is [keyFobStartFWD.ino](https://github.com/HarrisonLavins/ET5100_final_project/blob/main/arduino/platformController/keyFobStartFWD/keyFobStartFWD.ino)


## Lessons Learned 
Overall, I was happy with the result of the project in learning to assemble a mechatronic system using an original electronics design built from scratch and very minimal pre-assembled parts and libraries. I also enjoyed getting a chance to work hands-on with mecanum wheels and RFID sensors for the first time. 

The results were slightly different than I had hoped, since of the four motor controller boards purchased and tried to integrate with the design, only one seemed to work reliably enough to use in the project. Since each motor controller only supports up to 2 motors, and a +5V output, this meant that I could only power either the front or rear pair of motors. Unfortunately due to time and cost constraints, I decided to change the design to a front-wheel drive system for now, which could be improved over time to include all four wheels given some additional research into a more dependable motor driver board.

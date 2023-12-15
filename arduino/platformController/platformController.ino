// connect motor controller pins to Arduino digital pins
// motor one - Left Rear
int enA = 11; // PWM pin
int LR_pos = 13;
int LR_neg = 12;
// motor two - Right Rear
int enB = 10; // PWM pin
int RR_neg = 9;
int RR_pos = 8;

void setup() {
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(LR_pos, OUTPUT);
  pinMode(LR_neg, OUTPUT);
  pinMode(RR_neg, OUTPUT);
  pinMode(RR_pos, OUTPUT);
}

void forward() {
 //turn on motor A
  digitalWrite(LR_pos, HIGH);
  digitalWrite(LR_neg, LOW);
  analogWrite(enA, 200);   //set speed to 200 out of possible range 0-255

  //turn on motor B
  digitalWrite(RR_neg, LOW);
  digitalWrite(RR_pos, HIGH);
  analogWrite(enB, 200);   // set speed to 200 out of possible range 0-255
}

void reverse() {
 digitalWrite(LR_pos, LOW);
  digitalWrite(LR_neg, HIGH);
  digitalWrite(RR_neg, HIGH);
  digitalWrite(RR_pos, LOW);
}

void run() 
{
  //this function will run the motors in both directions at a fixed speed
  forward();
  delay(2000);

  //now change motor directions
  reverse();
  delay(2000);

//now turn off motors
  digitalWrite(LR_pos, LOW);
  digitalWrite(LR_neg, LOW);
  digitalWrite(RR_neg, LOW);
  digitalWrite(RR_pos, LOW);

}


void loop() {
  // test motors 
  run();
}

// connect motor controller pins to Arduino digital pins
// motor one - Left Front
int enA = 3; // PWM pin
int LF_pos = 2;
int LF_neg = 4;
// motor two - Right Front
int enB = 6; // PWM pin
int RF_neg = 7;
int RF_pos = 5;

// motor three - Right Rear
int enC = 10;  // PWM pin
int RR_pos = 9;
int RR_neg = 8;

// motor four - Left Rear
int enD = 11; // PWM pin
int LR_pos = 12; 
int LR_neg = 13;


void setup() {
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);

  pinMode(LR_pos, OUTPUT);
  pinMode(LR_neg, OUTPUT);
  pinMode(RR_neg, OUTPUT);
  pinMode(RR_pos, OUTPUT);

  pinMode(LF_pos, OUTPUT);
  pinMode(LF_neg, OUTPUT);
  pinMode(RF_neg, OUTPUT);
  pinMode(RF_pos, OUTPUT);
}

void forward() {
 //turn on motor A
  digitalWrite(LR_pos, HIGH);
  digitalWrite(LR_neg, LOW);
  analogWrite(enD, 200);   //set speed to 200 out of possible range 0-255

  //turn on motor B
  digitalWrite(RR_neg, LOW);
  digitalWrite(RR_pos, HIGH);
  analogWrite(enC, 200);   // set speed to 200 out of possible range 0-255

  //turn on motor C
  digitalWrite(LF_pos, HIGH);
  digitalWrite(LF_neg, LOW);
  analogWrite(enA, 200);   //set speed to 200 out of possible range 0-255

  //turn on motor D
  digitalWrite(RF_neg, HIGH);
  digitalWrite(RF_pos, LOW);
  analogWrite(enB, 200);   // set speed to 200 out of possible range 0-255
}

void reverse() {
  digitalWrite(LR_pos, LOW);
  digitalWrite(LR_neg, HIGH);
  digitalWrite(RR_neg, HIGH);
  digitalWrite(RR_pos, LOW);

  digitalWrite(LF_pos, LOW);
  digitalWrite(LF_neg, HIGH);
  digitalWrite(RF_neg, LOW);
  digitalWrite(RF_pos, HIGH);
}

// Direction: a char 'L' or 'R' to move sideways left or right, respectively
void sideways(char direction) {
  if (direction == 'R') {
  digitalWrite(RF_neg, LOW);
  digitalWrite(RF_pos, HIGH);
  digitalWrite(LR_pos, LOW);
  digitalWrite(LR_neg, HIGH);
  digitalWrite(LF_pos, HIGH);
  digitalWrite(LF_neg, LOW);
  digitalWrite(RR_pos, HIGH);
  digitalWrite(RR_neg, LOW);
  } else if (direction == 'L') {
  digitalWrite(RF_neg, HIGH);
  digitalWrite(RF_pos, LOW);
  digitalWrite(LR_pos, HIGH);
  digitalWrite(LR_neg, LOW);
  digitalWrite(LF_pos, LOW);
  digitalWrite(LF_neg, HIGH);
  digitalWrite(RR_pos, LOW);
  digitalWrite(RR_neg, HIGH);
  }
}

void pivot(char direction) {
  if (direction == 'R') {
  digitalWrite(LF_pos, HIGH);
  digitalWrite(LF_neg, LOW);
  digitalWrite(RF_neg, LOW);
  digitalWrite(RF_pos, HIGH);

  digitalWrite(RR_neg, HIGH);
  digitalWrite(RR_pos, LOW);
  digitalWrite(LR_pos, HIGH);
  digitalWrite(LR_neg, LOW);
  }
}

void run() 
{
  //this function will run the motors in both directions at a fixed speed
  forward();
  delay(2000);

  //now change motor directions
  reverse();
  delay(2000);

  sideways('R');
  delay(2000);

  sideways('L');
  delay(2000);

  pivot('R');
  delay(4000);

//now turn off motors
  digitalWrite(LR_pos, LOW); //rear
  digitalWrite(LR_neg, LOW);
  digitalWrite(RR_neg, LOW);
  digitalWrite(RR_pos, LOW);

  digitalWrite(LF_pos, LOW); //front
  digitalWrite(LF_neg, LOW);
  digitalWrite(RF_neg, LOW);
  digitalWrite(RF_pos, LOW);
}


void loop() {
  // test motors 
  run();
}

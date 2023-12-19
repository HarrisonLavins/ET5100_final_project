/************************************************************************************
 * Created By: Harrison Lavins
 * Created On: December 16, 2023

 Final project for ET 5100
 **********************************************************************************/

#include <SPI.h>
#include <MFRC522.h>

// ------- Setup for Key Reader ----------

#define SS_PIN 10
#define RST_PIN 9

byte readCard[4];
const String MasterTag = "4F1091B9"; //Master key fob ID
String tagID = "";

// Create class instances
MFRC522 mfrc522(SS_PIN, RST_PIN);


// ------- Setup for Motor Drivers (Front-Wheel Drive only) ----------
// connect motor controller pins to Arduino digital pins
// motor one - Left Front
int enA = 3; // PWM pin
int LF_pos = 2;
int LF_neg = 4;
// motor two - Right Front
int enB = 6; // PWM pin
int RF_neg = 7;
int RF_pos = 5;



// setup() function
void setup() 
{
 // Setup for motor drivers
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(LF_pos, OUTPUT);
  pinMode(LF_neg, OUTPUT);
  pinMode(RF_neg, OUTPUT);
  pinMode(RF_pos, OUTPUT);


  // Setup for key reader
  Serial.begin(9600);
  SPI.begin();

  mfrc522.PCD_Init();
  delay(4);
  //Show details of Card Reader
  mfrc522.PCD_DumpVersionToSerial();
  
  Serial.println("--------------------------");
  Serial.println(" Waiting for a Key... ");
}

void forward() {
  //turn on Left Front motor
  digitalWrite(LF_pos, HIGH);
  digitalWrite(LF_neg, LOW);
  analogWrite(enA, 200);   //set speed to 200 out of possible range 0-255

  //turn on Right Front motor
  digitalWrite(RF_neg, HIGH);
  digitalWrite(RF_pos, LOW);
  analogWrite(enB, 200);   // set speed to 200 out of possible range 0-255
}

void reverse() {
  digitalWrite(LF_pos, LOW);
  digitalWrite(LF_neg, HIGH);
  digitalWrite(RF_neg, LOW);
  digitalWrite(RF_pos, HIGH);
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
  digitalWrite(LF_pos, LOW); //front
  digitalWrite(LF_neg, LOW);
  digitalWrite(RF_neg, LOW);
  digitalWrite(RF_pos, LOW);
}


// loop() function
void loop() 
{
  //----------------------------------------------------------------------
  //Wait until new tag is available
  while (getID()) {

    if (tagID == MasterTag){
      Serial.println(" Starting Car!");
      Serial.println("--------------------------");
       // Start the car
       run();
      Serial.println(" Running! ");
    }

    else{
      Serial.println(" Invalid Key!");
      Serial.println("--------------------------");
    }

    delay(2000);
    Serial.println(" Waiting for a Key... ");
  }
  //----------------------------------------------------------------------
}

// getID() function
// Read new tag if available
boolean getID() 
{
  // Getting ready for Reading PICCs
  //If a new PICC placed to RFID reader continue
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }
  //Since a PICC placed get Serial and continue
  if ( ! mfrc522.PICC_ReadCardSerial()) {
  return false;
  }
  tagID = "";
  // The MIFARE PICCs that we use have 4 byte UID
  for ( uint8_t i = 0; i < 4; i++) {
  // Adds the 4 bytes in a single String variable
  tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  tagID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading
  return true;
  
}
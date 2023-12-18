/************************************************************************************
 * Created By: Harrison Lavins
 * Created On: December 16, 2023
 **********************************************************************************/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

byte readCard[4];
const String MasterTag = "4F1091B9"; //Master key fob
String tagID = "";

// Create class instances
MFRC522 mfrc522(SS_PIN, RST_PIN);

// setup() function
void setup() 
{
  Serial.begin(9600);
  SPI.begin();

  mfrc522.PCD_Init();
  delay(4);
  //Show details of Card Reader
  mfrc522.PCD_DumpVersionToSerial();
  
  Serial.println("--------------------------");
  Serial.println(" Waiting for a Key... ");
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
       // TODO: Put the code for turning on the motors here
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
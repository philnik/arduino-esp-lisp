//------------------------------------------------------------------------------
// Include the IRremote library header
//
#include <IRremote.h>

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 2;
IRrecv irrecv(recvPin);



int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;
int delayTime = 2;
int stepping = 50;

//+=============================================================================
// Configure the Arduino
//
void  setup ( )
{
  Serial.begin(9600);   // Status message will be sent to PC at 9600 baud
  irrecv.enableIRIn();  // Start the receiver
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void moveForward() {
for (int i = 0 ; i < stepping ; i++ ) {  
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
    delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
    delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
    delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
    delay(delayTime);
}
}

void moveBackward() {
for (int i = 0 ; i < stepping ; i++ ) {  
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}
}  
  
void pullRope () {
    digitalWrite(13,LOW);
    digitalWrite(12, HIGH);
//    delayMicroseconds(10000); // Approximately 10% duty cycle @ 1KHz
}

void pushRope () {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
//    delayMicroseconds(10000); // Approximately 10% duty cycle @ 1KHz
}

void stopRope () {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
//    delayMicroseconds(10000); // Approximately 10% duty cycle @ 1KHz
}

//+=============================================================================
// The repeating section of the code
//
void  loop ( )
{
  decode_results  results;        // Somewhere to store the results

  if (irrecv.decode(&results)) {  // Grab an IR code
  //  dumpInfo(&results);           // Output the results
  //  dumpRaw(&results);            // Output the results in RAW format
  // dumpCode(&results);           // Output the results as source code
  Serial.println("");           // Blank line between entries
    switch (results.value) {
      case 0xFFA25D:
        Serial.println("on-off");
        stopRope();
        break;
      case 0xFF629D:
        Serial.println("mode");
        break;
      case 0xFFE21D:
        Serial.println("mute");
        break;
      case 0xFF22DD:
        Serial.println(">||");
        break;
      case 0xFF02FD:
        Serial.println("|<<");
        moveForward();
        break;
      case 0xFFC23D:
        Serial.println("|>>");
        moveBackward();
        break;
      case 0xFFE01F:
        Serial.println("EQ");
        break;
      case 0xFFA857:
        Serial.println("-");
        pushRope();
        break;
      case 0xFF906F:
        Serial.println("+");
        pullRope();
        break;
      case 0xFF6897:
        Serial.println("0");
        break;
      case 0xFF9867:
        Serial.println("replay");
        break;
      case 0xFFB04F:
        Serial.println("U/SD");
        pushRope();
        break;
      case 0xFF30CF:
        Serial.println("one");
        break;
      case 0xFF18E7:
        Serial.println("two");
        break;
      case 0xFF7A85:
        Serial.println("three");
        break;
      case 0xFF10EF:
        Serial.println("four");
        break;
      case 0xFF38C7:
        Serial.println("five");
        break;
      case 0xFF5AA5:
        Serial.println("six");
        break;
      case 0xFF42BD:
        Serial.println("seven");
        break;
      case 0xFF4AB5:
        Serial.println("eight");
        break;
      case 0xFF52AD:
        Serial.println("nine");
        break;
    }
          
    irrecv.resume();              // Prepare for the next value
  }
}







#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(10, 11); // RX, TX
Servo myservo;

//int pos = 0;
int onOff = 1;


void setup() {

  myservo.attach(9);


  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    // sirve para indicar que el puerto serial esta libre
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() { // run over and over
  if (mySerial.available()) {
    //Serial.write(mySerial.read());
    onOff = mySerial.read();   //puerto de terminal virtual
  }
  if (Serial.available()) {
    //mySerial.write(Serial.read());
    onOff = Serial.read();//puerto de la termina de arduino
    Serial.println(onOff);
  }
  if (onOff == 'A') {
    onOff = 0;
    myservo.write(90);

    // for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //  delay(15);                       // waits 15 ms for the servo to reach the position
    // }

    //for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    // myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //  delay(15);                       // waits 15 ms for the servo to reach the position
    //
    //}

  }
  else if (onOff == 'B') {
    onOff = 0;
    myservo.write(10);
    //  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    // myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);// waits 15 ms for the servo to reach the positio
    //}
    //         for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //     myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //   delay(15);                       // waits 15 ms for the servo to reach the position
    // }
      
  }


}

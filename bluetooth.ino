
/*
  Protocol:
  the App forawards a 4-5 byte String. 
  R100
  ^^^^
 The first char defines which motor is used.
 The rest defines a positive or negativ integer between -255-255.
 */



//importing libraries
#include <SoftwareSerial.h> 
#include <AFMotor.h>

//define the pins for the Bluetooth dongle
#define rxPin 3 
#define txPin 6

//define the pins for the motors 
AF_DCMotor motor_1(1);
AF_DCMotor motor_2(4);

 String input;
 //motor_1 ist rechts, motor_2 ist links
 int powerRight = 0;
 int powerLeft = 0;
 String inputSubStrings[2];
 SoftwareSerial BluetoothSerial =  SoftwareSerial(rxPin, txPin);
  
void setup() {
  Serial.begin(9600);
  BluetoothSerial.begin(9600),
  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  //defining the mode for the Bluetooth dongle pins
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

}

void loop() {
  while (BluetoothSerial.available()){
    delay(10);
    char c = BluetoothSerial.read();     
    if (c != 'X'){ 
      input += c;   
    } else if (c == 'X') {
      processBTInput();
      controlMotors();
      input = "";
    }
  }
}

void processBTInput(){
  Serial.println(input);
  inputSubStrings[0] = input.substring(0, 1);
  inputSubStrings[1] = input.substring(1, input.length());
  //(inputSubStrings[0] + " " + inputSubStrings[1] +  "\n");
 
}
void controlMotors(){
  int motorPower = inputSubStrings[1].toInt();
  if(inputSubStrings[0] == "L"){
    if(motorPower < 0){
      motor_2.run(BACKWARD);
      motorPower *= -1;
    }else if(motorPower > 0){
      motor_2.run(FORWARD);
    }
    //motorPower *= 3;
    motor_2.setSpeed(motorPower); 
  }
  else if(inputSubStrings[0] == "R"){
    if(motorPower < 0){
      motor_1.run(BACKWARD);
      motorPower *= -1;
    }else if(motorPower > 0){
      motor_1.run(FORWARD);
    }
    //motorPower *= 3;
    motor_1.setSpeed(motorPower);
  }
}


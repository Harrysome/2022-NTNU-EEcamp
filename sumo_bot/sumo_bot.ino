#include <MeMCore.h>

MeRGBLed rgbled_7(7,2);
MeUltrasonicSensor ultrasensorfront(PORT_3);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motorL(M1);
MeDCMotor motorR(M2);

int front=0;
void setup() {
  Serial.begin(9600);
}

void loop(){
  front=ultrasensorfront.distanceCm();
  
  if(front<10){
    light(255,0,0);
    forward(255);
    delay(2000);
    backward(100);
    delay(2000);
  }else{
    light(0,255,0);
    if(lineFinder.readSensors()==0){
      turnRight(250);
      delay(500);
    }
    else if(lineFinder.readSensors()==1){
       turnRight(250);
       delay(500);
    }
    else if(lineFinder.readSensors()==2){
       turnLeft(250);
       delay(500);
   }
    else if(lineFinder.readSensors()==3){
       forward(100);
    }
  }
}

void forward(int s){
  motorL.run(-s);
  motorR.run(s);
}
void turnLeft(int s){
  motorL.run(s);
  motorR.run(s);
}
void turnRight(int s){
  motorL.run(-s);
  motorR.run(-s);
}
void backward(int s){
  motorL.run(s);
  motorR.run(-s);
}

void Stop(){
  motorR.stop();
  motorL.stop();
}

void light(int r,int g,int b){
  rgbled_7.setColor(0,r,g,b);
  rgbled_7.show();
}

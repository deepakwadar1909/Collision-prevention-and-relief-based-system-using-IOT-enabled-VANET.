
#include <NewPing.h>



#define trig_pin A1 
#define echo_pin A2 

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); 

char getstr;
const int LeftMotorForward = 5;
const int LeftMotorBackward = 6;
const int RightMotorForward = 10;
const int RightMotorBackward = 11;
const int buzzer=8;

void _mForward()
{ 
  
  digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  Serial.println("go forward!");
}
void _mBack()
{
  
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  Serial.println("go back!");
}
void _mleft()
{
  
  digitalWrite(LeftMotorBackward, LOW); 
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  
  Serial.println("go left!");
}
void _mright()
{
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW); 
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  
}
void _mStop()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  Serial.println("Stop!");
}

void setup()
{ 
  
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  distance = readPing();
  delay(100);
}
void loop()
  { 
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20)
  {
   digitalWrite(buzzer,HIGH);
   delay(100);
  }

   else{ 
  getstr=Serial.read();
 if(getstr=='F')
  {
    _mForward();
  }
  else if(getstr=='B')
  {
    _mBack();
    delay(200);
  }
  else if(getstr=='R')
  {
    _mleft();
    delay(200);
  }
  else if(getstr=='L') 
  {
    _mright();
    delay(200);
  }
  else if(getstr=='X')
  {
     _mStop();     
  }
   }
   distance = readPing();
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

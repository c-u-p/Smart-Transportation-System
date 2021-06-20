#include <Servo.h>
Servo myservo;
int pos = 0;
const int enB = 2;
const int in3 = 4;
const int in4 = 3;
#define trigD1 14
#define echoD1 9
#define trigD2 16
#define echoD2 7
#define trigD3 15
#define echoD3 8
#define trigD4 17
#define echoD4 6
#define trigD5 18
#define echoD5 10
long duration1,duration2,duration3,duration4,duration5;
int distance1,distance2,distance3,
CSMSS College of Polytechnic, Aurangabad
33
pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);

myservo.attach(11);
myservo.write(90);
pinMode(12, OUTPUT);
pinMode(trigD1, OUTPUT);
pinMode(echoD1, INPUT);
pinMode(trigD2, OUTPUT);
pinMode(echoD2, INPUT);
pinMode(trigD3, OUTPUT);
pinMode(echoD3, INPUT);
pinMode(trigD4, OUTPUT);
pinMode(echoD4, INPUT);
pinMode(trigD5, OUTPUT);
pinMode(echoD5, INPUT);
Serial.begin(9600);

}
int allcalculateDistance()
{
 
CSMSS College of Polytechnic, Aurangabad
34
digitalWrite(trigD1,LOW);
delayMicroseconds(2);
digitalWrite(trigD1,HIGH);
delayMicroseconds(10);
duration1=pulseIn(echoD1,HIG
CSMSS College of Polytechnic, Aurangabad
35
Serial.print("distance2= ");
Serial.print(distance2);
Serial.println("Cm");
if(distance2<=5)
{
myservo.write(180); // tell servo to go to position in variable 'pos'
//delay(5);
}
digitalWrite(trigD3,LOW);
delayMicroseconds(2);
digitalWrite(trigD3,HIGH);
delayMicroseconds(10);
duration3=pulseIn(echoD3,HIGH);
distance3=duration3*0.034/2;
Serial.print("distance3= ");
Serial.print(distance3);
Serial.println("Cm");
if(distance3<=5)
{
myservo.write(0); // tell servo to go to position in variable 'pos'
//delay(5);
} 
CSMSS College of Polytechnic, Aurangabad
36
digitalWrite(trigD4,LOW);
delayMicroseconds(2);
digitalWrite(trigD4,HIGH);
delayMicroseconds(10);
duration4=pulseIn(echoD4,HIGH);
distance4=duration4*0.034/2;
Serial.print("distance4= ");
Serial.print(distance4);
Serial.println("Cm");
if(distance1<=8&&distance4>=8)
{
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enB, 220);
}

digitalWrite(trigD5,LOW);
delayMicroseconds(2);
digitalWrite(trigD5,HIGH);
delayMicroseconds(10);
duration5=pulseIn(echoD5,HIGH);
CSMSS College of Polytechnic, Aurangabad
37
distance5=duration5*0.034/2;
Serial.print("distance5= ");
Serial.print(distance5);
Serial.println("Cm");
digitalWrite(13,LOW);
if(distance5<6)
{
digitalWrite(12,HIGH);
}
else
{
digitalWrite(12,LOW);
}
if(distance5>11)
{
digitalWrite(12,HIGH);
delay(300);
digitalWrite(12,LOW);
delay(300);
}

}
CSMSS College of Polytechnic, Aurangabad
38
void loop()
{
myservo.write(90);
for(int i=0;i<=28;i++)
{
allcalculateDistance();
}
}

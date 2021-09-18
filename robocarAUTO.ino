#include <HCSR04.h>


//init the distance module
HCSR04 hc(11,10);//initialisation class HCSR04 (trig pin , echo pin)


//motor pins init
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor1speed = 6;

int motor2pin1 = 4;
int motor2pin2 = 5;
int motor2speed = 7;

//decion making varinbles
int dist_one;
int dist_two;
int dist_three;
int dist_four;

void turn(){

    //spin
    digitalWrite(motor1speed, 255);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2speed, 255);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    delay(1000);

    //stop
    digitalWrite(motor1speed, 255);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2speed, 255);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(500);
  }

// A function to implement bubble sort 
void sort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] < a[o+1]) {
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
                }
        }
    }
}

//function detimines which direction is better to go in based on distance form robot
void direction_pick(){

    digitalWrite(motor1speed, 255);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
  
    digitalWrite(motor2speed, 255);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    delay(1000);
    
    do{
      turn();
    }while(100 > hc.dist() );
}


void setup() {
  // put your setup code here, to run once:
  { Serial.begin(9600); }
  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1speed, OUTPUT);
  
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2speed, OUTPUT);

    

}

void loop() {
  // put your main code here, to run repeatedly:  

  digitalWrite(motor1speed, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2speed, 255);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  int i = hc.dist();
  Serial.println( hc.dist() );

  if(i < 15){
    direction_pick();
  }

}

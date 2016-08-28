#include <Servo.h>

Servo FR_1;
Servo FR_2;

Servo FL_1;
Servo FL_2;

Servo RR_1;
Servo RR_2;

Servo RL_1;
Servo RL_2;

Servo camera1_p;
Servo camera1_y;

Servo camera2_p;
Servo camera2_y;

int freq_delay = 0;
int angle = 0;
int anglep;
int anglem;
char x; 
int a, base;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FR_1.attach(12);
  FR_2.attach(13);
  
  FL_1.attach(2);
  FL_2.attach(3);
  
  RR_1.attach(4);
  RR_2.attach(5);
  
  RL_1.attach(6);
  RL_2.attach(7);
  
  camera1_p.attach(8);
  camera1_y.attach(9);
  
  camera1_p.attach(10);
  camera1_y.attach(11);

  FR_1.write(85);
  FR_2.write(95);
  FL_1.write(105);
  FL_2.write(100);
  
  RR_1.write(90);
  RR_2.write(90);
  RL_1.write(100);
  RL_2.write(100);
}

void forward(int angle, int freq_delay)
{
   //assuming initial position of servo is 90
    FR_1.write(17);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    FL_1.write(170);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
    
    RR_1.write(0);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    RL_1.write(180);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
   
    if (a==0)
    {
    FR_2.write(60);
    FL_2.write(140);
    RR_2.write(45);
    RL_2.write(140);
    delay(200);

    FR_2.write(140);
    FL_2.write(60);
    RR_2.write(128);
    RL_2.write(60);
    delay(200); 
   
    }
}

void backward(int angle, int freq_delay)
{
   //assuming initial position of servo is 90
  
    FR_1.write(160);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    FL_1.write(25);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
    
    RR_1.write(165);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    RL_1.write(25);   //same as above
    delay(int((angle*1000)/428)+freq_delay);

    if (a==0)
    {

    FR_2.write(60);
    FL_2.write(140);
    RR_2.write(45);
    RL_2.write(140);
    delay(200);

    FR_2.write(140);
    FL_2.write(60);
    RR_2.write(128);
    RL_2.write(60);
    delay(200); 
    

    }
}
  
void left(int angle, int freq_delay)
{
   //assuming initial position of servo is 90
    FR_1.write(85);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    FL_1.write(105);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
    
    RR_1.write(90);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    RL_1.write(100);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
   //anglep=base+(angle/2);
   //anglem=base-(angle/2);
    if(a==0)
    {

    FL_2.write(100);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
    RL_2.write(100);   //same as above
    delay(int((angle*1000)/428)+freq_delay);

    FR_2.write(60);
    RR_2.write(45);
    delay(200);

    FR_2.write(140);
    RR_2.write(128);
    delay(200);
    
    

    } 
}
void right(int angle, int freq_delay)
{
   //assuming initial position of servo is 90
    FR_1.write(85);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    FL_1.write(105);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
   //anglep=base+(angle/2);
   //anglem=base-(angle/2);
    
    RR_1.write(90);
    delay(int((angle*1000)/428)+freq_delay);  //calculating time required for servo motor to reach required angle and adding delay
                 //the given servo does 0.14 sec / 60 degrees <=> 428 degrees/sec
    RL_1.write(100);   //same as above
    delay(int((angle*1000)/428)+freq_delay);
  
    if (a==0)
    {
    FR_2.write(95);
    delay(int((angle*1000)/428)+freq_delay);  //100 ms delay for servo to move by 45 degrees
    RR_2.write(90);
    delay(int((angle*1000)/428)+freq_delay);  //100 ms delay for servo to move by 45 degrees
                 //keeping 250 for 90 degrees, 50ms extra

    
    FL_2.write(140);
    RL_2.write(140);
    delay(200);

    FL_2.write(60);
    RL_2.write(60);
    delay(200); 
    
   
    }
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
   a=0; 
   x=Serial.read();
  }
  freq_delay = 50 ; //get value from controller
  angle = 90;
  base=90;
  // get angle from controller
  if(x=='f')  //include condition for forward button
  {
   Serial.println("Inside forward"); 
   forward(angle,freq_delay); 
  } 
  //similarly for other directions  
  else if(x=='b')
  {
    Serial.println("inside backward");
    backward(angle,freq_delay);
  }
  else if(x=='r')
  {
    Serial.println("inside right");
    right(angle,freq_delay);
  }
  else if(x=='l')
  {
    Serial.println("inside left");
    left(angle,freq_delay);
  }
  else
  {
    Serial.println("Signal not clear");
    FR_1.write(85);
    FR_2.write(95);
    FL_1.write(105);
    FL_2.write(100);
    
    RR_1.write(90);
    RR_2.write(90);
    RL_1.write(100);
    RL_2.write(100);
  }
}

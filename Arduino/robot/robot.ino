#include<Servo.h>

#define mlf 11 //green
#define mlb 10 //yellow
#define mrb 6  // purple
#define mrf 5 //blue
#define sr2 9 //pink
#define sr1 8 //blue
#define sm 7 //red
#define sl1 4 //green
#define sl2 3 //white
#define r90 A0//yellow
#define r180 A1//blue

int white=0;
int black=1;
int lj,rj,T,bc;
Servo myservo;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos = 0;    // variable to store the servo position
int con = 0;
void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(7,INPUT);
  myservo.attach(A3);
  myservo2.attach(A2);
  myservo3.attach(A4);
  myservo4.attach(A5);

}

void loop() {

 if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black && lj==0 && rj==0 && T==0 && bc==0){
      goFront();
      delay(200);
    }
else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white && lj==0 && rj==0 && T==0 && bc==0){
      turnLeft90();
      lj++;
    }
   else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black && lj==1 && rj==0 && T==0 && bc==0){
      turnRight90();
      rj++;
    }
     else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==1 && rj==1 && T==0 && bc==0){
       park();
      gripOpen();
  mainArmDown();
  middleArmUp();
  gripClose();
  mainArmUp();
  delay(150);
  turn180();
  T++;
      bc=1;
    }
   
    else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==1 && rj==1 && T==1 && bc==1){
      turnRight90();
      T++;
    }
    else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==1 && rj==1 && T==2 && bc==1){
      goFront1();
      delay(500);
      rj++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==1 && rj==2 && T==2 && bc==1){
      turnLeft90();
      lj++;
    }
    else if(digitalRead(sl1)==white && digitalRead(sr1)==white && digitalRead(sl2)==white && digitalRead(sr2)==white  && lj==2 && rj==2 && T==2 && bc==1){
      goFront();      
      gripOpen();
      gripClose();
      turn180();
      T++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==2 && rj==2 && T==3 && bc==1){
      turnLeft90();
      T++;
    }
    else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==2 && rj==2 && T==4 && bc==1){
      goFront1();
      delay(100);
      lj++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==3 && rj==2 && T==4 && bc==1){
      goFront1();
      delay(500);
      park();
    }
    else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==1 && rj==1 && T==1 && bc==0){
      turn180();
      rj++;
    }
    else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==1 && rj==2 && T==1 && bc==0){
      goFront();
      delay(100);
      rj++;
    }
    else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==1 && rj==3 && T==1 && bc==0){//skip
      goFront1();
      delay(400);
      rj++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==1 && rj==4 && T==1 && bc==0){
      turn1801();
      lj++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==2 && rj==4 && T==1 && bc==0){
      turnLeft90();
      lj++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==3 && rj==4 && T==1 && bc==0){
      turnLeft90();
      T++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==3 && rj==4 && T==2 && bc==0){
      turnLeft90();
      T++;
    }
    else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==3 && rj==4 && T==3 && bc==0){
      turnLeft90();
      lj++;}
    else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==4 && rj==4 && T==3 && bc==0){
      turnLeft90();
      T++;}
      
    else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==4 && rj==4 && T==4 && bc==0){
      turn180();
      rj++;}
      else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==4 && rj==5 && T==4 && bc==0){
      goFront();
      delay(100);
      rj++;}
      else if(digitalRead(sl1)==white && digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==black  && lj==4 && rj==6 && T==4 && bc==0){//skip
      goFront1();
      delay(400);
      rj++;}
      else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==4 && rj==7 && T==4 && bc==0){
      turn1801();
      lj++;}
      else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==5 && rj==7 && T==4 && bc==0){
      turnLeft90();
      lj++;}
      else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==6 && rj==7 && T==4 && bc==0){
      turnLeft90();
      T++;}
      else if(digitalRead(sl1)==black && digitalRead(sr1)==black && digitalRead(sl2)==black && digitalRead(sr2)==black  && lj==6 && rj==7 && T==5 && bc==0){
      turnRight90();
      T++;}
      else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==6 && rj==7 && T==6 && bc==0){
      goFront1();
      delay(400);
      lj++;}
      else if(digitalRead(sl1)==black && digitalRead(sr1)==white && digitalRead(sl2)==black && digitalRead(sr2)==white  && lj==7 && rj==7 && T==6 && bc==0){
      goFront1();
      delay(400);
      lj++;}
    else{
      normal(); 
    }
}
void reverse(){
  digitalWrite(mlb,1);
  digitalWrite(mrb,1);
  analogWrite(mrf,LOW);
  analogWrite(mlf,LOW);
}


void normal(){
  if(digitalRead(sl1)==white && digitalRead(sr1)==white && digitalRead(sl2)==white && digitalRead(sr2)==white)
    goFront();
  else if(digitalRead(sl1)==black&& digitalRead(sr1)==white && digitalRead(sl2)==white && digitalRead(sr2)==white)
    turnLeft();
  else if(digitalRead(sl1)==white&& digitalRead(sr1)==black && digitalRead(sl2)==white && digitalRead(sr2)==white)
    turnRight();
  else
    park();
  }
void goFront1(){
  digitalWrite(mlb,LOW);
  digitalWrite(mrb,LOW);
  analogWrite(mrf,150);
  analogWrite(mlf,150);
}


void goFront(){
  digitalWrite(mlb,LOW);
  digitalWrite(mrb,LOW);
  analogWrite(mrf,125);
  analogWrite(mlf,125);
  }
  
void turnRight(){
  digitalWrite(mrf,LOW);
  digitalWrite(mlb,LOW);
  analogWrite(mlf,125);
  analogWrite(mrb,115);
  }
  
void turnLeft(){
  digitalWrite(mlf,LOW);
  digitalWrite(mrb,LOW);
  analogWrite(mlb,115);
  analogWrite(mrf,125);
  }
  
void park(){
  digitalWrite(mlf,LOW);
  digitalWrite(mlb,LOW);
  digitalWrite(mrf,LOW);
  digitalWrite(mrb,LOW);
  }

void turnLeft90(){
  int flag1=1;
  if(flag1==1){
    turnLeft();
    delay(500+analogRead(r90));
    flag1=0;
    }
}

void turnRight90(){
  int flag1=1;
  if(flag1==1){
    turnRight();
    delay(650);
    flag1=0;
    }
}

void turn180(){
  int flag1=1;
  if(flag1==1){
    turnRight1();
    delay(805+analogRead(r180));
    flag1=0;
    }
}
void turn1801(){
  int flag1=1;
  if(flag1==1){
    turnRight1();
    delay(830+analogRead(r180));
    flag1=0;
    }
}

void turnRight1(){
  digitalWrite(mrf,LOW);
  digitalWrite(mlb,LOW);
  analogWrite(mlf,140);
  analogWrite(mrb,150);
  }

void turnLeft1(){
  digitalWrite(mrf,140);
  digitalWrite(mlb,150);
  analogWrite(mlf,LOW);
  analogWrite(mrb,LOW);
  }




void mainArmDown() {
  for (pos = 40; pos <= 131; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }

}
void mainArmUp() {
  for (pos = 130; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
}
void middleArmDown() {
  for (pos = 90; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
}
void middleArmUp() {
  for (pos = 130; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
}
void gripOpen() {
  con = 120;
  for (pos = 30; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

    myservo3.write(pos);
    myservo4.write(con);
    con--;
    // tell servo to go to position in variable 'pos'
    delay(10);// tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position
  }
}
void gripClose() {
  con = 30;
  for (pos = 120; pos >= 30; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo3.write(pos);
    myservo4.write(con);
    con++;
    // tell servo to go to position in variable 'pos'
    delay(10);// tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position
  }
}


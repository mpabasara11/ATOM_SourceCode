//sensors
int sensorLL = 2;
int sensorLR = 3;
int sensorRL = 4;
int sensorRR = 5;

//left motor
int enA = 6;
int in1 = 7;
int in2 = 8;

//right motor
int enB = 11;
int in3 = 9;
int in4 = 10;



void setup() {
  pinMode(sensorLL, INPUT);
  pinMode(sensorLR, INPUT);
  pinMode(sensorRL, INPUT);
  pinMode(sensorRR, INPUT);


  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}



void loop() {

  int LL = digitalRead(sensorLL);
  int LR = digitalRead(sensorLR);
  int RL = digitalRead(sensorRL);
  int RR = digitalRead(sensorRR);


  //very very smooth left
  if ( ( LL == LOW &&  LR == HIGH)  && ( RL == LOW &&  RR == LOW)) {

    turnLeft(140, 160);
    
  }

  //very smooth left
  else if ( (LL == HIGH && LR == HIGH)  && (  RL == LOW &&   RR == LOW)) {

 
    turnLeft(140, 150);
  

  }

  //smooth left
  else if ( ( LL == HIGH &&  LR == LOW)  && ( RL == LOW &&  RR == LOW)) {


    turnLeft(140, 160);
    


  }

  }
   //hard left 90dig
  else if (( LL == HIGH &&  LR == HIGH)  && (  RL == HIGH &&   RR == LOW)) {

    turnLeft(0,220);
    delay(60);

  }

//junction
  else if (( LL == HIGH &&  LR == HIGH)  && (  RL == HIGH &&   RR == HIGH)) {

    turnLeft(100,240);
    delay(60);
    
       
  }

  //forward
  else if ((LL == LOW &&  LR == HIGH)  && (  RL == HIGH &&   RR == LOW)) {
 
    forward(128,128);
  
    


  }
  
  //very very smooth right
  else if ( ( LL == LOW &&  LR == LOW)  && ( RL == HIGH &&  RR == LOW)) {

    turnRight(100,110);
    



  }

  //very smooth right
  else if ((LL == LOW &&  LR == LOW) && (  RL == HIGH &&   RR == HIGH)) {

 
    turnRight(130, 100);
 


  }

  //smooth right
  else if (( LL == LOW && LR == LOW)  && (  RL == LOW && RR == HIGH)) {


  
    turnRight(130,100);
 


  }
   //out of track
  else if ((LL == LOW &&  LR == LOW)  && (  RL ==LOW &&   RR == LOW)) {

  turnRight(70,88);
  


  }
  

  //hard right 90dig
  else if ( (LL == LOW &&  LR == HIGH)  && (  RL == HIGH &&   RR == HIGH)) {


    turnRight(220, 0);
    
    

  }

  
}




////////////////////////////////////Method definition//////////////////////////////////////////

void forward(int x, int y) {

  //left
  analogWrite(enA, x);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  //right
  analogWrite(enB, y);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight(int x, int y) {

  //left
  analogWrite(enA, x );
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //right
  analogWrite(enB, y);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void turnLeft(int x, int y) {

  //left
  analogWrite(enA, x);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  //right
  analogWrite(enB, y);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

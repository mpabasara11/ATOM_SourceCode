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

    turnLeft(110, 130);
  }

  //very smooth left
  else if ( (LL == HIGH && LR == HIGH)  && (  RL == LOW &&   RR == LOW)) {


    turnLeft(100, 110);

  }

  //smooth left
  else if ( ( LL == HIGH &&  LR == LOW)  && ( RL == LOW &&  RR == LOW)) {


    turnLeft(110, 130);


  }

  //hard left 90dig
  else if (( LL == LOW &&  LR == HIGH)  && (  RL == HIGH &&   RR == HIGH)) {

    turnLeft(0, 150);
    //delay(25);

  }
  //junction
  else if (( LL == HIGH &&  LR == HIGH)  && (  RL == HIGH &&   RR == HIGH)) {

    turnLeft(100, 220);

  }

  //forward
  else if ((LL == LOW &&  LR == HIGH)  && (  RL == HIGH &&   RR == LOW)) {

    forward(65, 75);

    //delay(30);


  }


  //very very smooth right
  else if ( ( LL == LOW &&  LR == LOW)  && ( RL == HIGH &&  RR == LOW)) {

    turnRight(80, 90);



  }

  //very smooth right
  else if ((LL == LOW &&  LR == LOW) && (  RL == HIGH &&   RR == HIGH)) {


    turnRight(110, 90);


  }

  //smooth right
  else if (( LL == LOW && LR == LOW)  && (  RL == LOW && RR == HIGH)) {



    turnRight(120, 100);


  }
  //out of track
  else if ((LL == LOW &&  LR == LOW)  && (  RL == LOW &&   RR == LOW)) {


    turnRight(80, 90);


  }

  //hard right 90dig
  else if ( (LL == LOW &&  LR == HIGH)  && (  RL == HIGH &&   RR == HIGH)) {


    turnRight(180, 0);
    delay(25);


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

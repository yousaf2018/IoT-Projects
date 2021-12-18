//our L298N control pins
const int LeftMotorForward = 5;
const int LeftMotorBackward = 4;
const int RightMotorForward = 3;
const int RightMotorBackward = 2;

const int buzzerPin = 12;

const int flamePin1 = 11;
const int flamePin2 = 10;
const int flamePin3 = 9;

int Flame = HIGH;

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin1, INPUT);
  pinMode(flamePin2, INPUT);
  pinMode(flamePin3, INPUT);
}

void loop(){
  Flame = digitalRead(flamePin1);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    moveForward();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    moveStop();
  }
  
  Flame = digitalRead(flamePin2);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    turnLeft();
    moveForward();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    moveStop();
  }
  
  Flame = digitalRead(flamePin3);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    turnRight();
    moveForward();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    moveStop();
  }
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){
    
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW); 
}

void turnLeft(){
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

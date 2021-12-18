#define LeftMotorForward 5
#define LeftMotorBackward 4
#define RightMotorForward 3
#define RightMotorBackward 2

char str[2];
char i;

void setup() 
{
    Serial.begin(9600);
    pinMode(RightMotorForward, OUTPUT);
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorBackward, OUTPUT);
    pinMode(RightMotorBackward, OUTPUT);
}

void loop() 
{
    while(Serial.available())
    {
        char ch = Serial.read();
        str[i++] = ch;
        
        if(str[i-1] == '1')
        {
            Serial.println("Forward");
            moveForward();
            i = 0;
        }
    
        else if(str[i-1] == '2')
        {
            Serial.println("Backward");
            moveBackward();
            i = 0;
        }
    
        else if(str[i-1] == '3')
        {
            Serial.println("Right");
            turnRight();
            i = 0;
        }
        
        else if(str[i-1] == '4')
        {
            Serial.println("Left");
            turnLeft();
            i = 0;
        }
    
        else if(str[i-1] == '5')
        {
            Serial.println("Stop");
            moveStop();
            i = 0;
        }
    }
}

void moveForward()
{
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}

void moveBackward()
{
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);
  
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, LOW);
}

void turnLeft()
{
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}

void turnRight()
{
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);
    
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorForward, LOW);
}

void moveStop()
{
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorBackward, LOW);
}

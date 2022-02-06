const int IR_F = 12;
const int IR_L = 11;
const int IR_R = 10;

const int IN1 = 5;
const int IN2 = 4;
const int IN3 = 3;
const int IN4 = 2;

const int EN = 6;

int pwm = 80;

void setup() {
  
  Serial.begin(9600);    // Initialize serial communication at 9600 bits per second:

  pinMode(IR_F, INPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_R, INPUT);
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(EN, OUTPUT);
 
  analogWrite(EN, pwm);
}

void Stop()  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
      
}

void Front()  {  
    analogWrite(EN, pwm);
    //This function  will turn Motors front.
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
}

void Left()  { 
    
    analogWrite(EN, pwm+50);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    
}
  
void Right()  {
    analogWrite(EN, pwm+50);
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500);

}
  

void loop() {

  if (digitalRead(IR_F) == HIGH) {    // No obstacle in front
//    Serial.print('f');
    Front();
    
    delay(100);
  }
  else  {
    // Check for obstacles and decide direction to move in
    if (digitalRead(IR_L) == HIGH)  {   // No obstacle at the left, turn 90 deg left
//      Serial.print('l');
      Left();
    }
    else if(digitalRead(IR_R) == HIGH) {  // No obstacle at the right, turn 90 def right
//      Serial.print('r');
      Right();
    }
    else  {   // Obstacle in front, left and right so turn 180 degrees
//      Serial.print('b');
      Right();
      Right();
    }
  }
  
  Stop();
  
  Serial.print('\n');
  delay(100);
}

//float distance[3];
#define motor1 10
#define motor2 11
#define motor3 5
#define motor4 6
#define circle 1360   // Time in millis to complete a full circle
const float minDist = 20.0;
float dLeft, dRight, dCenter;
long duration;

int trigPin[3] = {12, 3, 8};  // Left, Right, Center
int echoPin[3] = {13, 4, 9};


float findDist(int trigPin, int echoPin)
{
  digitalWrite(trigPin , LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin , LOW);

  float duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(trigPin[i], OUTPUT);
    pinMode(echoPin[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  dCenter = findDist(trigPin[2], echoPin[2]);
  dRight = findDist(trigPin[1], echoPin[1]);
  dLeft = findDist(trigPin[0], echoPin[0]);

  Serial.println(dCenter);

  if (dCenter < minDist + 5) {
    reverse(1000);
    turnAbout();
  } else if (dRight < minDist) {
    turnLeft(circle / 4);
  } else if (dLeft < minDist) {
    turnRight(circle / 4);
  } else {
    forward(100);
  }
}

void forward(int millisec) {
  Serial.println("Forward");
  analogWrite(motor1, 180);
  analogWrite(motor2, 0);
  analogWrite(motor3, 180);
  analogWrite(motor4, 0);
  delay(millisec);
}

void reverse(int millisec) {
  Serial.println("Reverse");
  analogWrite(motor1, 0);
  analogWrite(motor2, 180);
  analogWrite(motor3, 0);
  analogWrite(motor4, 180);
  delay(millisec);
}
void turnLeft(int millisec) {
  Serial.println("Left");
  analogWrite(motor1, 0);
  analogWrite(motor2, 180);
  analogWrite(motor3, 180);
  analogWrite(motor4, 0);
  delay(millisec);
}

void stopMove(int millisec) {
  Serial.println("Stop");
  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor3, 0);
  analogWrite(motor4, 0);
  delay(millisec);
}

void turnRight(int millisec) {
  Serial.println("Right");
  analogWrite(motor1, 180);
  analogWrite(motor2, 0);
  analogWrite(motor3, 0);
  analogWrite(motor4, 180);
  delay(millisec);
}

void turnAbout() {
  Serial.println("Reverse");
  analogWrite(motor1, 180);
  analogWrite(motor2, 0);
  analogWrite(motor3, 0);
  analogWrite(motor4, 180);
  delay(circle / 2);
}    

    else
    {
       lcd.setCursor(0,1);
       lcd.print("PLZ Wear Helmet");
      digitalWrite(m1,LOW);//motor
      //digitalWrite(m2,HIGH);
    } 
}

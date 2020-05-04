//Set pin numbers according to your circuit//

const int ENA = 3;
const int IN1 = 2;
const int IN2 = 4;
const int IN3 = 6;
const int IN4 = 7;
const int ENB = 5;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
   //L298 N motor //
   
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  //Ultrasonic Sensor//
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

}

void loop() {
digitalWrite(trigPin, LOW);// Clears the trigPin//
delayMicroseconds(2);// Sets the trigPin on HIGH state for 10 micro seconds//
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds//
duration = pulseIn(echoPin, HIGH);// Calculating the distance//
distance= (duration*0.034/2);// Prints the distance on the Serial Monitor//
Serial.print("Distance: ");
Serial.println(distance);

//Forward//

if(distance>20)
  {
    analogWrite(ENA, 255);
    analogWrite(ENB, 236);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  //BACKWARD//
  
  else if(distance<20)
  {
    analogWrite(ENA, 255);
    analogWrite(ENB, 240);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW); //stop//
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  delay(500);
    analogWrite(ENA, 255);
    analogWrite(ENB, 236);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);  //BACKWARD//
    digitalWrite(IN4, HIGH);
    delay(500);
     analogWrite(ENA, 255);
    analogWrite(ENB, 240);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW); //stop//
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  delay(100);
  analogWrite(ENA, 255);
    analogWrite(ENB, 236);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);  //Right//
    digitalWrite(IN4, LOW);
    delay(650);
  }
  }

//Q) 02

#include <Servo.h>

// Define pins for ultrasonic sensor and servo motor
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;

// Create a Servo object
Servo dustbinServo;

// Define variables
long duration;
int distance;
int servoAngle;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set up the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach the servo motor to the defined pin
  dustbinServo.attach(servoPin);
  
  // Initialize the servo position
  dustbinServo.write(0); // Start with the door closed
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds to generate a pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.0344 / 2;
  
  // Display the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Determine the servo angle based on the distance
  if (distance <= 10) {
    servoAngle = 90;
  } else if (distance <= 20) {
    servoAngle = 60;
  } else if (distance <= 30) {
    servoAngle = 30;
  } else {
    servoAngle = 0;
  }
  
  // Set the servo to the calculated angle
  dustbinServo.write(servoAngle);
  
  // Wait for a short period before the next measurement
  delay(100);
}

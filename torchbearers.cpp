#include <Servo.h>
// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;
// Define the pins for the servo motors
const int servo1Pin = 3;
const int servo2Pin = 5;
const int servo3Pin = 7;
void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Attach the servo motors to their respective pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  // Set trigPin as output and echoPin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set servos to initial position
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  // Get the distance from the ultrasonic sensor
  long distance = getDistance();

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the distance is less than 10 cm
  if (distance < 10) {
    // Servo motor 1: 0° to 180°
    servo1.write(180);
    delay(5000); // Delay for 5 seconds

    // Servo motor 1: 180° to 0°
    servo1.write(0);
    delay(5000); // Delay for 5 seconds

    // Servo motor 2: 0° to 45°
    servo2.write(45);
    delay(2000); // Delay for 2 seconds

    // Servo motor 2: 45° to 0°
    servo2.write(0);
     delay(1000);// Delay for 2 seconds
    
    servo3.write(60);
    delay(3000); // Delay for 2 seconds

    // Servo motor 2: 45° to 0°
    servo3.write(0);
    delay(2000); 
    
  }
  else 
  {servo1.write(0);
   servo2.write(0);
   servo3.write(0);
  } 

  // Small delay before taking the next reading
  delay(100);
}

// Function to get the distance from the ultrasonic sensor
long getDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, and calculate the distance
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  long distance = duration * 0.034 / 2;

  return distance;
}

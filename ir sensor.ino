// Define pins for the ultrasonic sensor
const int trigPin = 10;
const int echoPin = 9;

// Define the pin for the buzzer
const int buzzerPin = 8;

// Define variables to store distance and duration
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the trigPin as an output
  pinMode(trigPin, OUTPUT);

  // Set the echoPin as an input
  pinMode(echoPin, INPUT);

  // Set the buzzerPin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Sound the buzzer at different frequencies based on the distance
  if (distance <= 10) {
    tone(buzzerPin, 1000); // 1 kHz
  } else if (distance <= 20) {
    tone(buzzerPin, 800);  // 800 Hz
  } else if (distance <= 30) {
    tone(buzzerPin, 600);  // 600 Hz
  } else if (distance <= 40) {
    tone(buzzerPin, 400);  // 400 Hz
  } else {
    noTone(buzzerPin); // Turn off the buzzer
  }

  // Wait for a short period before the next measurement
  delay(1000);
}

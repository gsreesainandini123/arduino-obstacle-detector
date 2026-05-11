// Pins for Ultrasonic Sensor HC-SR04
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 8;

// Configurable threshold for obstacle detection
const int safetyDistance = 120; 

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
  // High baud rate is supported in Tinkercad for faster Serial Monitor updates
  Serial.begin(9600); 
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the returning pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance: (speed of sound * time) / 2
  // Using 0.0344 for slightly higher precision in cm/us
  distance = duration * 0.0344 / 2; 

  // Threshold logic: Trigger buzzer if an object is within safety range
  // Tinkercad ultrasonic sensor returns 0 or large values if out of range
  if (distance > 0 && distance < safetyDistance) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  // Serial Monitor feedback for debugging the simulation
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 100ms delay offers a good balance between responsiveness and simulation stability
  delay(100); 
}

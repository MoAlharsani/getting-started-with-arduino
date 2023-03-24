
int trigPin = 8;    // Trigger pin of the HC-SR04 sensor
int echoPin = 9;    // Echo pin of the HC-SR04 sensor


int pingTimeTraveled;    // Time it takes for the ping to travel from the sensor to the object and back
int speedOfSound = 343;  // Speed of sound in m/s 

float timeInSeconds;    // Time in seconds that the ping takes to travel to the object and back
float distanceIncm;     // Distance in centimeters from the sensor to the object

void setup() {
  // Set the trigger and echo pins as output and input respectively
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to the trigger pin of the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time it takes for the ping to travel to the object and back
  pingTimeTraveled = pulseIn(echoPin, HIGH); // Will count the time while the echo pin is high
  timeInSeconds = pingTimeTraveled / 1000000.0; // Convert ping time to seconds

  // Calculate the distance in centimeters using the formula: distance = (time * speed of sound) / 2
  distanceIncm = (timeInSeconds * speedOfSound) / 2.0 * 100; // Convert distance to centimeters

  // Print the distance to the serial monitor
  Serial.print("Object is ");
  Serial.print(distanceIncm);
  Serial.println(" cm from the sensor");

  // Wait for 100 milliseconds before taking another measurement
  delay(100);
}

int trigPin = 8;
int echoPin = 9;

int pingTimeTraveled;

int speedOfSound = 343;

int speed;
float traveledTimeInSeconds;

int traveledDistance = 30; // Distance in meters

int detectedObjectTime1;
int detectedObjectTime2;

bool isDetected = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTimeTraveled = pulseIn(echoPin, HIGH);

  if((pingTimeTraveled > 150)&&(pingTimeTraveled < 1500)){
    detectedObjectTime1 = millis();
    Serial.println("start time is detected");
    delay(1000);
    while(true){
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pingTimeTraveled = pulseIn(echoPin, HIGH);
      if((pingTimeTraveled > 150)&&(pingTimeTraveled < 1500)){
        Serial.println("Finish time is detected");
        detectedObjectTime2 = millis();
        isDetected = true;
        break;
      }
    }
  }


  if(isDetected){
    traveledTimeInSeconds = (detectedObjectTime2 - detectedObjectTime1) / 1000.;
    Serial.print("It took the object ");
    Serial.print(traveledTimeInSeconds);
    Serial.println("s to run 30 meter");

    speed = traveledDistance / traveledTimeInSeconds;
    Serial.print("Speed of the detected object is ");
    Serial.print(speed);
    Serial.println(" m/s");
    isDetected = false;
    delay(1000);
  }
}

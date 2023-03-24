int lightPin = A0;
int BuzzerPin = 10;

int lightValue;

int photoresistorpowerPin = 8;
int BuzzerPowerPin = 10;






void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(8, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000);

  digitalWrite(photoresistorpowerPin, HIGH);
  lightValue = analogRead(lightPin);

  while(lightValue < 120){                   // 120 is the photoresistor reading while the light is ON
    digitalWrite(BuzzerPowerPin, HIGH);
    lightValue = analogRead(lightPin);
  }

  digitalWrite(BuzzerPowerPin, LOW);

  delay(10000);

}



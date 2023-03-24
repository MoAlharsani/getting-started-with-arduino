int timeBetweenLetters = 3000;
int timeBetweenWords = 7000;

int timeBetweenDotsDashesWithinTheSameLetter = 1000;

int dotTime = 1000;
int dashTime = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
}

void loop() {
  // I = O 

  digitalWrite(2, HIGH);
  delay(dotTime);
  digitalWrite(2, LOW);

  delay(timeBetweenDotsDashesWithinTheSameLetter);

  digitalWrite(2, HIGH);
  delay(dotTime);
  digitalWrite(2, LOW);

  delay(timeBetweenLetters);

   // E = O

  digitalWrite(2, HIGH);
  delay(dotTime);
  digitalWrite(2, LOW);

  delay(timeBetweenLetters);

   // E = O

  digitalWrite(2, HIGH);
  delay(dotTime);
  digitalWrite(2, LOW);
  
  delay(timeBetweenLetters);

   // E = O

  digitalWrite(2, HIGH);
  delay(dotTime);
  digitalWrite(2, LOW);

  delay(timeBetweenWords);
  
} // at this curely brackets, it will jump quickly to the first line the in loop function

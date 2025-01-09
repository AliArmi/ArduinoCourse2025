int letter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 2; i < 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    letter = Serial.read() - 95;
    if (2 <= letter && letter <= 6) {
      digitalWrite(letter, HIGH);
    } else {
      for (int i = 2; i < 7; i++) {
        digitalWrite(i, LOW);
      }
    }
  }
}

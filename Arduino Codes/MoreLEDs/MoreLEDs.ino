uint8_t green = 7;
uint8_t yellow = 8;
uint8_t red = 12;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red, HIGH);
  Serial.println("STOOOP!");
  delay(1000);
  digitalWrite(red, LOW);

  digitalWrite(yellow, HIGH);
  Serial.println("waaaaaiiiit");
  delay(1000);
  digitalWrite(yellow, LOW);

  digitalWrite(green, HIGH);
  Serial.println("GO! GO! GO!");
  delay(1000);
  digitalWrite(green, LOW);
  
}

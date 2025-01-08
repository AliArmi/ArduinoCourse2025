uint8_t green = 7;
uint8_t yellow = 8;
uint8_t red = 12;
const int o = HIGH;
const int z  = LOW;


void OnOff(char One, char Two, char Three) {
  digitalWrite(green, One);
  digitalWrite(yellow, Two);
  digitalWrite(red, Three);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}
void loop() {
  OnOff(z,z,z);
  Serial.println("0");
  delay(500);

  OnOff(z, z, o);
  Serial.println("1");
  delay(500);

  OnOff(z, o, z);
  Serial.println("2");
  delay(500);

  OnOff(z, o, o);
  Serial.println("3");
  delay(500);

  OnOff(o, z, z);
  Serial.println("4");
  delay(500);

  OnOff(o, z, o);
  Serial.println("5");
  delay(500);

  OnOff(o, o, z);
  Serial.println("6");
  delay(500);

  OnOff(o, o, o);
  Serial.println("7");
  delay(500);

  // put your main code here, to run repeatedly:

}

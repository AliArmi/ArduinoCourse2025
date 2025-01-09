float V, Temp, In;

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(A0, INPUT);
  
  
}

void loop() {
  In = analogRead(A0);
  V = In * 5 / 1023;
  Temp = V/0.01;
  Serial.print(Temp);
  Serial.print("C");
  Serial.println(u8"\u00b0");
}

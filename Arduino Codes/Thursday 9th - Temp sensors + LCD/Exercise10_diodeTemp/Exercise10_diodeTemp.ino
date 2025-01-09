float V, Temp, In;

void TempToColour(float T){
  for (byte i=2; i<5; i++){
    digitalWrite(i, LOW);
    }
  
  if (T < 24) {
    digitalWrite(2, HIGH);  // Green
  } 
  else if (T > 24 && T < 26) {
    digitalWrite(3, HIGH);  // Yellow
  } 
  else if (T > 26) {
    digitalWrite(4, HIGH);  // Red
  }
}


void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(A0, INPUT);
  
  for (byte i=2; i<5; i++){
    pinMode(i, OUTPUT);
  }
  
}

void loop() {

  In = analogRead(A0);
  V = In * 5 / 1023;
  Temp = V/0.01;

  Serial.print(Temp);
  Serial.print("C");
  Serial.println(u8"\u00b0");

  TempToColour(Temp);
  
  

}

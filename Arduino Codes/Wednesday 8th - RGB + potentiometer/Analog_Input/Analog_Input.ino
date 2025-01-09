byte pins[3] = {3, 5, 6};
int knobcurrent, knob;
float factor = 1023/5;
byte V;

byte R, G, B;
byte newRGB[3] = {R, G, B};
byte currentRGB[3] = {0, 0, 0}; 
byte oldCol, newCol;
int i = 0;
byte blue;


void redTOpurple(byte V) {
  blue = (255/5.015)*V;
  newRGB[0] = blue;
  fade(blue);
}


void fade(byte nB) {
  while (currentRGB[0] != newRGB[0]) {
    oldCol = currentRGB[0];
    newCol = newRGB[0];
    
    if (newCol < oldCol) {
      currentRGB[0]--;
    } else if (newCol > oldCol) {
      currentRGB[0]++;
    }
    analogWrite(3, currentRGB[0]);
    delay(10);
  }
}


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++){    // setup pins 3, 5, 6
    pinMode(pins[i], OUTPUT);
  }
  pinMode(A0, INPUT);
  analogWrite(pins[2], 255);
}

void loop() {
  knob = analogRead(A0);
  if (knob != (knobcurrent + 1) && knob != (knobcurrent -1) && knob != knobcurrent){
    Serial.print(knob);
    Serial.print(" = ");
    Serial.print(knob / factor, 3);  // Print with 3 decimal places
    Serial.println(" V");
  }
  knobcurrent = knob;
  redTOpurple(knob / factor);
  delay(10);

}

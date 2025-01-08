byte R, G, B;
byte newRGB[3] = {R, G, B};
byte currentRGB[3] = {0, 0, 0}; 
byte oldCol, newCol, pin;
int i = 0;
byte pins[3] = {3, 5, 6};


void fade(byte nR, byte nG, byte nB) {
  while (currentRGB[0] != newRGB[0] || currentRGB[1] != newRGB[1] || currentRGB[2] != newRGB[2]) {
    oldCol = currentRGB[i];
    newCol = newRGB[i];
    
    if (newCol < oldCol) {
      currentRGB[i]--;
    } else if (newCol > oldCol) {
      currentRGB[i]++;
    }
    analogWrite(pins[i], currentRGB[i]);
    i = (i + 1) % 3;  // Cycle through 0, 1, 2
    delay(10);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++){    // setup pins 3, 5, 6
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    newRGB[0] = Serial.parseInt();
    newRGB[1] = Serial.parseInt();
    newRGB[2] = Serial.parseInt();
    fade(newRGB[0], newRGB[1], newRGB[2]);
  }

}

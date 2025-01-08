uint8_t green = 7;
uint8_t yellow = 8;
uint8_t red = 12;
uint8_t but = 13;

bool lastButtonState = LOW; // Tracks the previous button state
bool ledState = LOW;        // Tracks the current LED state

void setup() {
  Serial.begin(115200);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(but, INPUT_PULLUP);
}

void loop() {
  bool currentButtonState = digitalRead(but);

  if (currentButtonState == LOW && lastButtonState == HIGH) { // if difference in value, to make sure it only happens when you initialy press

    ledState = !ledState; // Invert led
    digitalWrite(green, ledState);
    delay(50); // debouncing
  }

  
  lastButtonState = currentButtonState; // Update the button state
}

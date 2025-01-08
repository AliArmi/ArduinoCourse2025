

const uint8_t ledPin = 12; // defining the ledPin
const int tU = 200; //timeUnit


void led(uint8_t Type) {  // High 1 or Low 0
  if (Type == 1) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}

void DD(uint8_t len) {  //Dot or Dash
  if (len == 0){ // dot
    led(1);
    delay(tU);
    led(0);
  }
  else {   // dash
    led(1);
    delay(tU*3);
    led(0);
  }
  delay(tU);
}

int S[] = {0, 0, 0};
int O[] = {1, 1, 1};

int A[] = {0, 1};
int L[] = {0, 1, 0, 0};
int I[] = {0, 0};


void morse(int letter[], uint8_t len) {

  for (int i = 0; i < len; i++){
    DD(letter[i]);
  }
}

void setup() {
  
  pinMode(ledPin, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}

void loop() {

  morse(A, sizeof(A) / sizeof(A[0]));
  morse(L, sizeof(L) / sizeof(L[0]));
  morse(I, sizeof(I) / sizeof(I[0]));

}

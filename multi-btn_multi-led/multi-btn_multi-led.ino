const int inputPin = A0;
const int outPin1 = 10;
const int outPin2 = 11;
const int outPin3 = 12;
const int outPin4 = 13;

int buttonState1 = LOW;
int b1[1] = {1013};
int buttonState2 = LOW;
int b2[2] = {1003, 1004};
int buttonState3 = LOW;
int b3[3] = {976, 977, 978};
int buttonState4 = LOW;
int b4[3] = {943, 944, 945};

int buttonState;
int lastButtonState;

unsigned long lastDebounceTime = 0;
unsigned long debounceTime = 50;

void setup() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(outPin1, OUTPUT);
  pinMode(outPin2, OUTPUT);
  pinMode(outPin3, OUTPUT);
  pinMode(outPin4, OUTPUT);
  Serial.begin(9600);
}   

void loop() {
  int reading = analogRead(inputPin);
  Serial.println(reading);

  if (inArray(b1, 1, reading)) {
    buttonState1 = !buttonState1;    
    digitalWrite(outPin1, buttonState1);
  } else if (inArray(b2, 2, reading)) {
    buttonState2 = !buttonState2;    
    digitalWrite(outPin2, buttonState2);
  } else if (inArray(b3, 3, reading)) {
    buttonState3 = !buttonState3;    
    digitalWrite(outPin3, buttonState3);
  } else if (inArray(b4, 3, reading)) {
    buttonState4 = !buttonState4;
    digitalWrite(outPin4, buttonState4);
  }
  
  delay(111);
}

bool inArray(int a[], int num, int value) {
  int i;
  for (i=0; i<num; i++) {
    if (a[i] == value) {
      return true;
    }
  }

  return false;
}



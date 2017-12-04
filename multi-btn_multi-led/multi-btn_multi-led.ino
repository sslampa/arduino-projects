const int inputPin = A0;
const int outPin1 = 10;
const int outPin2 = 11;
const int outPin3 = 12;
const int outPin4 = 13;

int buttonState1 = LOW;
int buttonState2 = LOW;
int buttonState3 = LOW;
int buttonState4 = LOW;

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

  if (reading >= 1010) {
    buttonState1 = !buttonState1;    
    digitalWrite(outPin1, buttonState1);
  } else if (reading >= 1000 && reading < 1010) {
    buttonState2 = !buttonState2;    
    digitalWrite(outPin2, buttonState2);
  } else if (reading >= 970 && reading < 1000) {
    buttonState3 = !buttonState3;    
    digitalWrite(outPin3, buttonState3);
  } else if (reading >= 940 && reading < 970) {
    buttonState4 = !buttonState4;
    digitalWrite(outPin4, buttonState4);
  }
  
  delay(110);
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



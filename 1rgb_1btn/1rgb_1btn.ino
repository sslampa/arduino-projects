const int redPin = 13;
const int greenPin = 12;
const int bluePin = 11;
const int btnPin = 2;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int red = 255;
int green = 0;
int blue = 0;

int lastColor = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(btnPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  
  }
  Serial.println(reading);

  if ((millis() - lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:
  
      // if the button state has changed:
      if (reading != buttonState) {
        buttonState = reading;
  
        // only toggle the LED if the new button state is HIGH
        if (buttonState == LOW) {
          Serial.println("Here");
          if (lastColor == 0) {
            red = 0;
            green = 255;
            blue = 0;
            lastColor = 1;
          } else if (lastColor == 1) {
            red = 0;
            green = 0;
            blue = 255;
            lastColor = 2; 
          } else {
            red = 255;
            green = 0;
            blue = 0;
            lastColor = 0;
          }
        }
      }
    } 

    setColor(red, green, blue);
  
    // save the reading. Next time through the loop, it'll be the lastButtonState:
    lastButtonState = reading;

}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);    
}

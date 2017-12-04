const int redPin = 13;
const int greenPin = 12;
const int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
 setColor(90, 45, 129);
 delay(500);
 setColor(200, 16, 46);
 delay(500);
 setColor(0, 70, 135);
 delay(500);
 setColor(180, 151, 90);
 delay(500);
 setColor(0, 0, 0);
 delay(500);
 setColor(255, 255, 0);
 delay(500);
 setColor(184, 134, 11);
 delay(500);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);    
}



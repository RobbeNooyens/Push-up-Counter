#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const double maxDistance = 23;
int counter = 0;

enum State {up, down};
State upOrDown = up;

// Pins
const int trigPin = 2, echoPin = 4, led = 8, maxSensorDistance = 500;

NewPing sonar(trigPin, echoPin, maxSensorDistance);
LiquidCrystal_I2C lcd(0x3F, 2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(20,4); // for 16 x 2 LCD module
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.noCursor();
  lcd.setCursor(9,1);
  lcd.print(counter);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);
  checkDistance(distance);
  delay(50);
}

void checkDistance(int distance){
  if(distance < maxDistance) {
    digitalWrite(led, HIGH);
    if(upOrDown == up){
      upOrDown = down;
    }
  } else if(upOrDown == down) {
    upOrDown = up;
    addPushup();
    lcd.clear();
    lcd.setCursor(9,1);
    lcd.print(counter);
  } else {
    digitalWrite(led, LOW);
  }
}

void addPushup(){
  counter += 1;
}

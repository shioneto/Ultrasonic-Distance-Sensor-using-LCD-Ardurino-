#include <LiquidCrystal.h>

const int trig = 7; 
const int echo = 6; 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long totaltime;
int distance; // Added missing semicolon

void setup() {
  // Initialize the LCD and pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2); // Corrected missing semicolon
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure echo time
  totaltime = pulseIn(echo, HIGH);

  // Calculate distance in centimeters
  distance = (totaltime * 0.0343) / 2;

  // Display distance on LCD
  lcd.setCursor(0, 1); // Move to the second row
  lcd.print(distance);
  lcd.print(" cm"); // Add "cm" for clarity
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100); // Add delay to stabilize readings
}

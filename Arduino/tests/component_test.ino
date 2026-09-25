#include <Servo.h>

Servo testServo;

// Pin configuration
#define BUZ 2
#define SERVO_PIN 3
#define RAIN 4
#define LED1 5
#define LED2 6

void setup()
{
  Serial.begin(9600);

  pinMode(BUZ, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(RAIN, INPUT);

  testServo.attach(SERVO_PIN);

  // Initial state
  digitalWrite(BUZ, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  Serial.println("================================");
  Serial.println("RAINSHIELD HARDWARE TEST");
  Serial.println("================================");

  // LED TEST
  Serial.println("Testing LED1...");
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);

  Serial.println("Testing LED2...");
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);

  // BUZZER TEST
  Serial.println("Testing Buzzer...");
  digitalWrite(BUZ, HIGH);
  delay(500);
  digitalWrite(BUZ, LOW);

  // SERVO TEST
  Serial.println("Testing Servo...");

  testServo.write(90);
  Serial.println("Servo -> 90 degrees");
  delay(1000);

  testServo.write(0);
  Serial.println("Servo -> 0 degrees");
  delay(1000);

  testServo.write(90);
  Serial.println("Servo -> 90 degrees");
  delay(1000);

  Serial.println("================================");
  Serial.println("Sensor monitoring started");
  Serial.println("================================");
}

void loop()
{
  int rain = digitalRead(RAIN);

  if (rain == LOW)
  {
    Serial.println("RAIN SENSOR: RAIN DETECTED");
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }
  else
  {
    Serial.println("RAIN SENSOR: DRY");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }

  delay(1000);
}

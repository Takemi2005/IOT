#define led_blink 10

void setup() {
  pinMode(led_blink, OUTPUT);
}

void loop() {
  digitalWrite(led_blink, HIGH);
  delay(1000);
  digitalWrite(led_blink, LOW);
  delay(5000);
}
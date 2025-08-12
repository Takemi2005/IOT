void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  digitalWrite(10, HIGH);
  delay(5000); 

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(2000); 

  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(7000); 

  digitalWrite(8, LOW);
}
int ledState = LOW;        
int lastButtonState = LOW; 
int currentButtonState;    

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  currentButtonState = digitalRead(2);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
   
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    
    delay(50);
  }
  digitalWrite(13, ledState);
  lastButtonState = currentButtonState;
}
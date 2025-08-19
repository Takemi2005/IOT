const int pinoLED = 9; 

void setup() {
  // O comando analogWrite() já faz isso internamente.
}

void loop() {
  // Aumentar o brilho (de 0 a 255)
  for (int i = 0; i <= 255; i++) {
    analogWrite(pinoLED, i);
    delay(10); 
  }

  // Diminuir o brilho (de 255 a 0)
  for (int i = 255; i >= 0; i--) {
    analogWrite(pinoLED, i);
    delay(10);
  }
}
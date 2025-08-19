const int pinosLED[] = {2, 3, 4, 5};
const int numeroDePinos = 4;
int contador = 0;

void setup() {
  for (int i = 0; i < numeroDePinos; i++) {
    pinMode(pinosLED[i], OUTPUT);
  }}

void loop() {
  for (int i = 0; i < numeroDePinos; i++) {
    int bitStatus = bitRead(contador, i);
    digitalWrite(pinosLED[i], bitStatus);
  }

  contador++;
  if (contador >= 16) {
    contador = 0;
  }
  delay(500);
  }

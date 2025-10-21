// Definição dos pinos onde os LEDs estão conectados
// Usamos a palavra 'const int' para definir que o número do pino não vai mudar
const int LED_VERMELHO = 13;
const int LED_AMARELO  = 12;
const int LED_VERDE    = 11;

// Definição dos tempos (em milissegundos)
// 1 segundo = 1000 milissegundos
const int TEMPO_VERMELHO = 5000; // 5 segundos
const int TEMPO_AMARELO  = 2000; // 2 segundos
const int TEMPO_VERDE    = 5000; // 5 segundos

void setup() {
  // Configura os pinos como SAÍDA (OUTPUT), pois o Arduino irá enviar energia (controlar os LEDs)
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERDE,    OUTPUT);
}

void loop() {
  // 1. ESTADO VERDE
  // Liga o LED Verde e desliga os outros
  digitalWrite(LED_VERDE,    HIGH); // HIGH = LIGA (nível lógico alto)
  digitalWrite(LED_AMARELO,  LOW);  // LOW  = DESLIGA (nível lógico baixo)
  digitalWrite(LED_VERMELHO, LOW);

  // Espera o tempo definido para o Verde
  delay(TEMPO_VERDE);

  // 2. TRANSIÇÃO: VERDE -> AMARELO
  // Apaga o Verde, acende o Amarelo
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  HIGH); // LIGA o Amarelo
  digitalWrite(LED_VERMELHO, LOW);

  // Espera o tempo definido para o Amarelo
  delay(TEMPO_AMARELO);

  // 3. ESTADO VERMELHO
  // Apaga o Amarelo, acende o Vermelho
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, HIGH); // LIGA o Vermelho

  // Espera o tempo definido para o Vermelho
  delay(TEMPO_VERMELHO);
  
  // 4. TRANSIÇÃO: VERMELHO -> VERDE (ou Amarelo Piscante, dependendo da região)
  // No ciclo simples, após o Vermelho, ele volta diretamente para o Verde (e o loop se repete)

}
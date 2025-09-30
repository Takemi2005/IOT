// 1. Incluir a biblioteca LiquidCrystal I2C
// Certifique-se de que esta biblioteca esteja instalada em sua IDE Arduino.
#include <LiquidCrystal_I2C.h>

// Definir os pinos dos LEDs conforme o seu circuito
const int LED_VERMELHO = 7;   // LED Vermelho conectado ao pino D7
const int LED_AMARELO  = 6;   // LED Amarelo conectado ao pino D6
const int LED_VERDE    = 5;   // LED Verde conectado ao pino D5

// Inicializar o objeto LCD.
// O endereço I2C é comumente 0x27 ou 0x3F. Se 0x27 não funcionar, tente 0x3F.
// O display é 16 colunas e 2 linhas.
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Configurar os pinos dos LEDs como SAÍDA
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERDE,    OUTPUT);

  // --- Configuração do LCD ---
  lcd.init();      // Inicializa o LCD
  lcd.backlight(); // Liga a luz de fundo (backlight)

  // Mensagem inicial no display
  lcd.setCursor(0, 0); // Define o cursor para a Coluna 0, Linha 0
  lcd.print("Projeto Arduino"); 
  
  lcd.setCursor(0, 1); // Define o cursor para a Coluna 0, Linha 1
  lcd.print("LEDs + LCD I2C!");
  
  delay(2000); // Exibe a mensagem por 2 segundos
  lcd.clear(); // Limpa o display para a rotina do loop
}

void loop() {
  // Rotina de Semáforo (exemplo simples)

  // 1. LUZ VERDE
  lcd.setCursor(0, 0);
  lcd.print("Estado: VERDE   "); // Espaços para apagar texto anterior
  lcd.setCursor(0, 1);
  lcd.print("Siga em frente! ");
  digitalWrite(LED_VERMELHO, LOW);  // Desliga
  digitalWrite(LED_AMARELO,  LOW);  // Desliga
  digitalWrite(LED_VERDE,    HIGH); // Liga
  delay(4000); // Permanece VERDE por 4 segundos

  // 2. LUZ AMARELA (Aviso)
  lcd.setCursor(0, 0);
  lcd.print("Estado: AMARELO ");
  lcd.setCursor(0, 1);
  lcd.print("Atencao!        ");
  digitalWrite(LED_VERMELHO, LOW);  // Desliga
  digitalWrite(LED_AMARELO,  HIGH); // Liga
  digitalWrite(LED_VERDE,    LOW);  // Desliga
  delay(2000); // Permanece AMARELO por 2 segundos

  // 3. LUZ VERMELHA
  lcd.setCursor(0, 0);
  lcd.print("Estado: VERMELHO");
  lcd.setCursor(0, 1);
  lcd.print("PARE!           ");
  digitalWrite(LED_VERMELHO, HIGH); // Liga
  digitalWrite(LED_AMARELO,  LOW);  // Desliga
  digitalWrite(LED_VERDE,    LOW);  // Desliga
  delay(5000); // Permanece VERMELHO por 5 segundos

  // O loop continuará repetindo esta sequência
}
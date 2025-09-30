// Inclui a biblioteca para o display LCD I2C
#include <LiquidCrystal_I2C.h>

// Inicializa o objeto LCD: Endereço (0x27), Colunas (16), Linhas (2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define os pinos digitais dos LEDs
int vermelho = 7;
int amarelo = 6;
int verde = 5;

// --- Função de Configuração (SETUP) ---
void setup() {
  // Inicializa o LCD
  lcd.init();
  // Liga a luz de fundo do LCD
  lcd.backlight();
  // Limpa qualquer texto no display
  lcd.clear();

  // Configura os pinos dos LEDs como SAÍDA
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}

// --- Função Principal (LOOP) ---
void loop() {
  // 1. LED VERMELHO Liga
  lcd.setCursor(0, 0); // Define o cursor na coluna 0, linha 0 (primeira linha)
  lcd.print("VERMELHO ON_"); // Escreve no LCD
  digitalWrite(vermelho, HIGH); // Liga o LED Vermelho
  digitalWrite(amarelo, LOW);   // Desliga o LED Amarelo
  digitalWrite(verde, LOW);     // Desliga o LED Verde
  delay(500); // Espera 500 milissegundos (0,5 segundo)

  // 2. LED VERMELHO Desliga
  lcd.setCursor(0, 0);
  lcd.print("VERMELHO OFF_"); // Atualiza o LCD
  digitalWrite(vermelho, LOW); // Desliga o LED Vermelho
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW);
  delay(500);

  // 3. LED AMARELO Liga
  lcd.setCursor(0, 0);
  lcd.print("AMARELO ON__"); // Escreve no LCD
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH); // Liga o LED Amarelo
  digitalWrite(verde, LOW);
  delay(500);

  // 4. LED AMARELO Desliga
  lcd.setCursor(0, 0);
  lcd.print("AMARELO OFF_"); // Atualiza o LCD
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW); // Desliga o LED Amarelo
  digitalWrite(verde, LOW);
  delay(500);

  // 5. LED VERDE Liga
  lcd.setCursor(0, 0);
  lcd.print("VERDE ON____"); // Escreve no LCD
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, HIGH); // Liga o LED Verde
  delay(500);

  // 6. LED VERDE Desliga
  lcd.setCursor(0, 0);
  lcd.print("VERDE OFF___"); // Atualiza o LCD
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW); // Desliga o LED Verde
  delay(500);
}
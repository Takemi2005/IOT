// Inclui as bibliotecas necessárias
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

#define pino_echo 10
#define pino_trigger 9
// Endereço I2C do seu módulo LCD (o mais comum é 0x27 ou 0x3F)
// Se não funcionar, você pode precisar executar um código "I2C Scanner" para descobrir o endereço correto.
LiquidCrystal_I2C lcd(0x27, 16, 2); // (Endereço, Colunas, Linhas)
Ultrasonic ultrasonic(pino_trigger, pino_echo);
// Definição dos pinos
const int PINO_SENSOR = A0;      // Pino para o sensor de porta/janela (Reed Switch)
const int PINO_LED_VERDE = 5;    // Pino para o LED Verde (Status: Fechado)
const int PINO_LED_VERMELHO = 7; // Pino para o LED Vermelho (Status: Aberto)

void setup() {
  // Inicialização do LCD
  lcd.init();
  lcd.backlight();

  // Mensagem de inicialização no LCD
  lcd.setCursor(0, 0);
  lcd.print("Monitor de Status");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  
  // Configura os pinos dos LEDs como SAÍDA
  pinMode(PINO_LED_VERDE, OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  
  // Configura o pino do sensor como ENTRADA
  // Usaremos INPUT_PULLUP para simplificar a fiação:
  // - O pino estará HIGH por padrão.
  // - Quando o sensor (Reed Switch) fechar o circuito para o GND (porta fechada), o pino vai para LOW.
  pinMode(PINO_SENSOR, INPUT_PULLUP); 

  // Se você usou uma configuração com resistor de PULL-DOWN, use:
  // pinMode(PINO_SENSOR, INPUT); 
  // E inverta a lógica (HIGH = FECHADO, LOW = ABERTO)
  
  delay(2000); // Espera para a mensagem de inicialização
  lcd.clear();
}

void loop() {
  // Lê o estado do sensor de porta/janela
  int statusSensor = digitalRead(PINO_SENSOR);
  
  // Lê a distância do sensor ultrassônico (em cm)
  long distancia = ultrasonic.read();
  // Define um limite de distância para alerta
  const int limiteDistancia = 20; // 20 cm
  
  // Lógica para os LEDs baseada nos dois sensores
  if (distancia < limiteDistancia) {
    // Se a porta estiver aberta ou objeto próximo (distância menor que limite)
    
    digitalWrite(PINO_LED_VERMELHO, HIGH); // Liga LED Vermelho
    digitalWrite(PINO_LED_VERDE, LOW);     // Apaga LED Verde
    
    // Exibe no LCD
    lcd.setCursor(0, 0);
    lcd.print("Porta/Janela:");
    lcd.setCursor(0, 1);
    lcd.print("    ABERTA     ");
  } else {
    // Porta fechada e distância segura
    
    digitalWrite(PINO_LED_VERMELHO, LOW);  // Apaga LED Vermelho
    digitalWrite(PINO_LED_VERDE, HIGH);    // Liga LED Verde
    
    lcd.setCursor(0, 0);
    lcd.print("Porta/Janela:");
    lcd.setCursor(0, 1);
    lcd.print("    FECHADA     ");
  }
  
  delay(500); // atraso para evitar sobrecarga
}

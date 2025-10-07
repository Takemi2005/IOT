// ------------------------------------
//          BIBLIOTECAS
// ------------------------------------
#include <Wire.h>          // Comunicação I2C (necessário para o LCD)
#include <LiquidCrystal_I2C.h> // Biblioteca para o LCD 16x2 com I2C
#include "DHT.h"           // Biblioteca para o sensor DHT

// ------------------------------------
//          CONFIGURAÇÕES
// ------------------------------------

// --- LCD I2C ---
// Configura o LCD (endereço 0x27, 16 colunas, 2 linhas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- SENSOR DHT ---
const int DHT_PIN = 3;     // O pino de dados do DHT está no pino digital 3
const int DHT_TYPE = DHT11;  // Estamos usando o sensor modelo DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// --- CONTROLE DE TEMPO (Non-Blocking Delay) ---
const long INTERVALO_LEITURA = 2000; // Ler a cada 2000 ms (2 segundos)
unsigned long tempoAnterior = 0;     // Armazena o tempo da última leitura

// ------------------------------------
//              SETUP
// ------------------------------------
void setup() {
  // Inicializa a comunicação Serial (útil para debug)
  // Serial.begin(9600); 

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();

  // Inicializa o sensor DHT
  dht.begin();

  // Mensagem inicial no LCD
  lcd.setCursor(0, 0);
  lcd.print("Estacao Climat.");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  
  // Um pequeno delay no setup é aceitável, mas pode ser removido
  // para acelerar o início do loop. 
  delay(1500); 
}

// ------------------------------------
//              LOOP
// ------------------------------------
void loop() {
  // Pega o tempo atual do Arduino
  unsigned long tempoAtual = millis();

  // Verifica se o tempo decorrido é maior ou igual ao intervalo
  if (tempoAtual - tempoAnterior >= INTERVALO_LEITURA) {
    // Se sim, marca o tempo atual como o da última leitura
    tempoAnterior = tempoAtual;

    // 1. LER OS DADOS
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    // 2. VERIFICAR FALHA NA LEITURA
    // Verifica se a leitura falhou (retorna 'nan' - Not a Number)
    if (isnan(temperatura) || isnan(umidade)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Falha na leitura");
      lcd.setCursor(0, 1);
      lcd.print("do sensor!");
      // Serial.println("Falha na leitura do sensor DHT!");
      return; // Sai e tenta de novo no próximo ciclo do loop
    }

    // 3. ATUALIZAR O DISPLAY LCD (Leitura bem-sucedida)
    
    // Limpa a tela para os novos dados
    lcd.clear(); 

    // --- TEMPERATURA (Linha 1) ---
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura, 1); // Imprime com 1 casa decimal
    // O caractere 223 é o símbolo de grau (°) na tabela de caracteres do LCD
    lcd.print((char)223); 
    lcd.print("C");

    // --- UMIDADE (Linha 2) ---
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade, 1); // Imprime com 1 casa decimal
    lcd.print(" %");
  }
}
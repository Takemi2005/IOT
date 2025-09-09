// Biblioteca do DHT
#include "DHT.h"

// Porta usada e tipo de sensor
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Variável para armazenar a temperatura
float temperatura;

void setup() {
  Serial.begin(9600);   // Inicializando o monitor serial
  dht.begin();          // Inicializando o sensor
}

void loop() {
  delay(2000);  // Aguarda dois segundos entre as leituras

  // Lê a temperatura em Celsius
  temperatura = dht.readTemperature();

  // Verificando se existe erro na leitura da temperatura
  if (isnan(temperatura)) {
    Serial.println("ERRO NO SENSOR!");
  } else {
    // Se tudo funcionar, envia a temperatura para a serial
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");
  }
}
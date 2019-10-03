//Teste de equipamentos disponiveis no momento


#include "DHT.h"

#define DHTPIN 2     // Onde o pino é conectado
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define fan 4

int maxUm = 60;
int maxTemp = 40;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(fan, OUTPUT);
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // Delay entre as medições.
  delay(2000);

  // Lendo temperaturas ou umidade por volta de 20 milisegundos
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float u = dht.readHumidity();
  // Ler a temperatura em Celsius
  float t = dht.readTemperature();
  
  // Verfifica e indica erro de not a number na leitura e tenta novamente
  if (isnan(u) || isnan(t)) {
    Serial.println("E!");
    return;
  }
  
  if(u > maxUm || t > maxTemp) {
      digitalWrite(fan, HIGH);
  } else {
     digitalWrite(fan, LOW); 
  }
  
//  Serial.print("Umidity: "); 
  Serial.print(u);
//  Serial.print(" %\t");
//  Serial.print("Temperatura: "); 
  Serial.print(t);
//  Serial.println(" *C ");

}

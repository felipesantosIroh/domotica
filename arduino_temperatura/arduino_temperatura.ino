//Teste de equipamentos disponiveis no momento


#include "DHT.h"

#define DHTPIN 2      //Pino onde o sensor é conectado
#define DHTTYPE DHT22   //DHT 22  (AM2302)
#define fan 4         //Pino do ventilador (ou LED simbolizando um ventilador)
#define led_sala 6    //Pino do led da sala

int maxUm = 60;
int maxTemp = 40;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(led_sala, OUTPUT);
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // Delay entre as medições.
  delay(2000);

  // Lendo temperaturas ou umidade por volta de 2 segundos (sensor é lento)
  int u = dht.readHumidity();
  // Ler a temperatura em Celsius
  int t = dht.readTemperature();
  
  // Verfifica e indica erro de not a number na leitura e tenta novamente
  if (isnan(u) || isnan(t)) {
    Serial.println("E!");
    return;
  }
  
  if(u > maxUm || t > maxTemp) {
     digitalWrite(fan, HIGH); //liga ventilador
  } else {
     digitalWrite(fan, LOW); //desliga ventilador
  }
  
//  Serial.print("Umidade: "); 
  Serial.println(u);
//  Serial.print(" %\t");
//  Serial.print("Temperatura: "); 
  Serial.println(t);
//  Serial.println(" *C ");

//lendo da serial, caso tenha algum dado recebendo
if (Serial.available()){
  
  switch(Serial.read()){
    
    case 'a': //Ligar o LED da sala
      digitalWrite(led_sala, HIGH);
      break;
      
    case 'b': //Desligar o LED da sala
      digitalWrite(led_sala, LOW);
      break;
    
  }
}


}

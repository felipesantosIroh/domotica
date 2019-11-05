//Teste de equipamentos disponiveis no momento


#include "DHT.h"

#define DHTPIN 2      //Pino onde o sensor é conectado
#define DHTTYPE DHT22   //DHT 22  (AM2302)
#define fan 4         //Pino do ventilador (ou LED simbolizando um ventilador)
#define luzSala 8     //Pino do led da Sala
#define luzQuarto 9     //Pino do led do Quarto
#define luzCozinha 10    //Pino do led da Cozinha
#define luzGaragem 11    //Pino do led da Garagem
#define luzBanheiro 12    //Pino do led do Banheiro
#define luzCorredor 13    //Pino do led do Corredor

int maxUm = 60;
int maxTemp = 40;
char a = 0;
char b = 0;
char c = 0;
char d = 0;
char e = 0;
char f = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(luzSala, OUTPUT);
  pinMode(luzQuarto, OUTPUT);
  pinMode(luzCozinha, OUTPUT);
  pinMode(luzGaragem, OUTPUT);
  pinMode(luzBanheiro, OUTPUT);
  pinMode(luzCorredor, OUTPUT);
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
//  Serial.println(u);
//  Serial.print(" %\t");
//  Serial.print("Temperatura: "); 
  Serial.println(t);
//  Serial.println(" *C ");

//lendo da serial, caso tenha algum dado recebendo
if (Serial.available()){
  
  switch(Serial.read()){
    
    case 'a': //Ligar a LUZ da Sala
      if(a == 0){
        digitalWrite(luzSala, HIGH);
        a = 1;
        break;
      } else{
        digitalWrite(luzSala, LOW);
        a = 0;
        break;
      }

      
    case 'b': //Ligar a LUZ do Quarto
      if(b == 0){
        digitalWrite(luzQuarto, HIGH);
        b = 1;
        break;
      } else{
        digitalWrite(luzQuarto, LOW);
        b = 0;
        break;
      }


    case 'c': //Ligar a LUZ da Cozinha
      if(c == 0){
        digitalWrite(luzCozinha, HIGH);
        c = 1;
        break;
      } else{
        digitalWrite(luzCozinha, LOW);
        c = 0;
        break;
      }
      
    case 'd': //Ligar a LUZ da Garagem
      if(d == 0){
        digitalWrite(luzGaragem, HIGH);
        d = 1;
        break;
      } else{
        digitalWrite(luzGaragem, LOW);
        d = 0;
        break;
      }

    case 'e': //Ligar a LUZ do Banheiro
      if(e == 0){
        digitalWrite(luzBanheiro, HIGH);
        e = 1;
        break;
      } else{
        digitalWrite(luzBanheiro, LOW);
        e = 0;
        break;
      }

    case 'f': //Ligar a LUZ do Corredor
      if(f == 0){
        digitalWrite(luzCorredor, HIGH);
        f = 1;
        break;
      } else{
        digitalWrite(luzCorredor, LOW);
        f = 0;
        break;
      }
  }
}


}

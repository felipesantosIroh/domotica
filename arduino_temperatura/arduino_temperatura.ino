#include <stdio.h>
#include "DHT.h"

#define buzzer 5          //Pino do buzzer
#define DHTPIN 2          //Pino do Primeiro sensor DHT
#define DHTPIN2 3         //Pino do Segundo sensor  DHT
#define DHTTYPE DHT22     //DHT 22  (AM2302)
#define DHTTYPE2 DHT11    //DHT 11
#define PIR 4             //Pino do sensor PIR     
#define luzSala 8         //Pino do led da Sala
#define luzQuarto 9       //Pino do led do Quarto
#define luzCozinha 10     //Pino do led da Cozinha
#define luzGaragem 11     //Pino do led da Garagem
#define luzBanheiro 12    //Pino do led do Banheiro
#define luzCorredor 13    //Pino do led do Corredor

int i = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int valorSensorPIR = 0;
int tom = 1500;

DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE2);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(luzSala, OUTPUT);
  pinMode(luzQuarto, OUTPUT);
  pinMode(luzCozinha, OUTPUT);
  pinMode(luzGaragem, OUTPUT);
  pinMode(luzBanheiro, OUTPUT);
  pinMode(luzCorredor, OUTPUT);
  pinMode(PIR, INPUT);
  Serial.begin(9600); 
  dht.begin();
  dht2.begin();
}

void loop() {
  // Delay entre as medições.
  delay(2000);

  // Lendo temperaturas ou umidade por volta de 2 segundos (sensor é lento)
  int u = dht.readHumidity();
  // Ler a temperatura em Celsius
  int t = dht.readTemperature();
  // Lendo temperaturas ou umidade por volta de 2 segundos (sensor é lento)
  int u2 = dht2.readHumidity();
  // Ler a temperatura em Celsius
  int t2 = dht2.readTemperature();

  valorSensorPIR = digitalRead(PIR);
  //Verificando se ocorreu detecção de movimentos
  if (valorSensorPIR == 1) {
    tom = 329;
    ligarAlarme();
  } else {
    desligarAlarme();
  }

  // Verfifica e indica erro de not a number na leitura e tenta novamente
  if (isnan(u) || isnan(t)) {
    Serial.println("E!");
    return;
  }

  if (isnan(u2) || isnan(t2)) {
    Serial.println("E!");
    return;
  }  

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

       case 'p': //Ligar alarme sonoro
          tom = 1500;
          ligarAlarme();

    }
  }

    char buffer [50];
     //Temperatura dht22 || temperatura dht11 || PIR || SALA || QUARTO || COZINHA || GARAGEM || BANHEIRO || CORREDOR                       
     i=sprintf (buffer, "%d %d %d %d %d %d %d %d %d\n", t, t2, valorSensorPIR, a, b, c, d, e, f);
    for(int l= 0; l<=i; l++)
    Serial.print(buffer[l]);
}

void ligarAlarme() {   
  //Ligando o buzzer com uma frequencia de 1500 hz.
  tone(buzzer, tom); 
  delay(2000); //tempo que o buzzer toca
   
  desligarAlarme();
}
 
void desligarAlarme() {
  //Desligando o buzzer
  noTone(buzzer);
}

//Teste de equipamentos disponiveis no momento


#include "DHT.h"

#define buzzer 1          //Pino do buzzer
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

int contador = 0; //contador a cada dois segundos
int maxUm = 60;
int maxTemp = 56;
int passTemp = 0;
int passUmi = 0;
int passTemp2 = 0;
int passUmi2 = 0;
int variacaoTemp = 0;
int variacaoUmi = 0;
int variacaoTemp2 = 0;
int variacaoUmi2 = 0;
char a = 0;
char b = 0;
char c = 0;
char d = 0;
char e = 0;
char f = 0;
int valorSensorPIR = 0;

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
   
  Serial.print("Valor do Sensor PIR: ");  
  Serial.println(valorSensorPIR);
   
  //Verificando se ocorreu detecção de movimentos
  if (valorSensorPIR == 1) {
    ligarAlarme();
  } else {
    desligarAlarme();
  } 
/*
  //grava nas variaveis passadas a temperatura para calcular taxa
  if(contador == 30){ //se o tempo for 0 então guarda as infomações
    passTemp = t;
    passUmi = u;
    passTemp2 = t2;
    passUmi2 = u2;
    contador = 0;
  } else if(contador == 0){ //se o tempo for =! de 0 então calcula taxa
    variacaoTemp =  t - passTemp;
    variacaoUmi =  u - passUmi;
    variacaoTemp2 =  t2 - passTemp2;
    variacaoUmi2 =  u2 - passUmi2;
    contador = contador + 1;
  } else{
    contador = contador + 1;
  }
*/  
  // Verfifica e indica erro de not a number na leitura e tenta novamente
  if (isnan(u) || isnan(t)) {
    Serial.println("E!");
    return;
  }

  if (isnan(u2) || isnan(t2)) {
    Serial.println("E!");
    return;
  }  

/* 
  if((u > maxUm || t > maxTemp) || (variacaoTemp > 8 || variacaoUmi > 5)) {
     ligarAlarme();
  } else {
    desligarAlarme();
  }

  if((u2 > maxUm || t2 > maxTemp) || (variacaoTemp2 > 8 || variacaoUmi2 > 5)) {
     ligarAlarme();
  } else {
     desligarAlarme();
  }
*/  

//  Serial.println(u); 
  Serial.println(t);
//  Serial.println(u2);
  Serial.println(t2);

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

void ligarAlarme() {   
  //Ligando o buzzer com uma frequencia de 1500 hz.
  tone(buzzer,1500);
  digitalWrite(luzGaragem, HIGH); 
  delay(2000); //tempo que o buzzer toca
   
  desligarAlarme();
}
 
void desligarAlarme() {
  //Desligando o buzzer
  noTone(buzzer);
  digitalWrite(luzGaragem, LOW);
}

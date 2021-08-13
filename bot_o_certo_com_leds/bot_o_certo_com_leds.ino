//Declaração das constantes
const int led = 7;   //constante led refere-se ao pino digital 7.
const int botao = 2; //constante botão refere-se ao pino digital 2.
boolean braia = false;

//Variável que conterá os estados do botão (0 LOW, 1 HIGH).
int estadoBotao = 0;

//Método setup, executado uma vez ao ligar o Arduino.


int brightness = 0;
int fadeAmount = 5;
void setup() {
  pinMode(led,OUTPUT);  //Definindo pino digital 8 como de saída.
  pinMode(botao,INPUT); //Definindo pino digital 2 como de entrada. 
  attachInterrupt(digitalPinToInterrupt(2), ISR1, FALLING);
}

//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  if(braia){
     analogWrite(led, brightness);
     brightness = brightness + fadeAmount;
     if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
     }
     delay(500);
  } 
}

void ISR1(){
  braia = !braia;
    if(braia == false){
      analogWrite(led, LOW);
    }
  }

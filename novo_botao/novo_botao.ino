/*******************************************************************************
*
*       Push button com funão liga / desliga (qualquer montagem)
*                   http://squids.com.br/arduino
*
*******************************************************************************/

const int buttonPin = 2; // número do pino pushbutton
const int ledPin = 12; // número do pino LED
 
int estado = 0; // variável para leitura do pushbutton
int guarda_estado;  // variável para armazenar valores do pushbutton
 
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT); // utilize INPUT_PULLUP com resistor interno do Arduino
}
 
void loop(){
// le o estado pushbutton: ligado (HIGH) ou desligado (LOW)
estado = digitalRead(buttonPin); // le o estado do push button HIGH ou LOW

if (!estado) {  // verifica se o estado é LOW ou 0 (true)       
    guarda_estado = !guarda_estado; // inverte valor da variável guarda_estado
    while (!digitalRead(buttonPin)) {  } //esperera soltar o botão
    delay(50); 
}
 
if (guarda_estado == HIGH) {
    digitalWrite(ledPin, HIGH); // liga o led
} else {
    digitalWrite(ledPin, LOW); // liga o led
}
}

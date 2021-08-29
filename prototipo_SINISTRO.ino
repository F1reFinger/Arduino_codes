// C++ code
//
int pin8 = 8;
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int select = 0;
int timer = 100;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void knight_rider(){
	digitalWrite(pin3, HIGH);
   delay(timer);
   digitalWrite(pin3, LOW);
   delay(timer);

   digitalWrite(pin4, HIGH);
   delay(timer);
   digitalWrite(pin4, LOW);
   delay(timer);

   digitalWrite(pin5, HIGH);
   delay(timer);
   digitalWrite(pin5, LOW);
   delay(timer);

   digitalWrite(pin6, HIGH);
   delay(timer);
   digitalWrite(pin6, LOW);
   delay(timer);

   digitalWrite(pin7, HIGH);
   delay(timer);
   digitalWrite(pin7, LOW);
   delay(timer);

   digitalWrite(pin8, HIGH);
   delay(timer);
   digitalWrite(pin8, LOW);
   delay(timer);

   digitalWrite(pin7, HIGH);
   delay(timer);
   digitalWrite(pin7, LOW);
   delay(timer);

   digitalWrite(pin6, HIGH);
   delay(timer);
   digitalWrite(pin6, LOW);
   delay(timer);

   digitalWrite(pin5, HIGH);
   delay(timer);
   digitalWrite(pin5, LOW);
   delay(timer);

   digitalWrite(pin4, HIGH);
   delay(timer);
   digitalWrite(pin4, LOW);
   delay(timer);
}

void fade(){
	analogWrite(pin3, brightness);
    analogWrite(pin4, brightness);
    analogWrite(pin5, brightness);
    analogWrite(pin6, brightness);
    analogWrite(pin7, brightness);
    analogWrite(pin8, brightness);
  	// change the brightness for next time through the loop:
  	brightness = brightness + fadeAmount;
  		if(brightness <= 0){
    		delay(10);
    	}
  		if (brightness <= 0 || brightness >= 255) {
    		fadeAmount = -fadeAmount;
  		}
  	// wait for 30 milliseconds to see the dimming effect
  	delay(13);
}

void ISR1(){
  if(select == 2){
    select = 0;
  }
  else{
    select++;
  }
}

void setup()
{
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), ISR1, FALLING);
}

void loop()
{
  if (select == 1) {
   knight_rider();
  }else if (select == 2){
   fade();
  }
  else {
  	analogWrite(pin3, LOW);
    analogWrite(pin4, LOW);
    analogWrite(pin5, LOW);
    analogWrite(pin6, LOW);
    analogWrite(pin7, LOW);
    analogWrite(pin8, LOW);
  }
}
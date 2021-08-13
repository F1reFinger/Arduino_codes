#define pinoled 4
#define pinosensor 2

bool led;

void setup ()
{
 pinMode(pinoled, OUTPUT);
 pinMode(pinosensor, INPUT);

 digitalWrite(pinoled,led);
}

void loop ()
{
 if(digitalRead(pinosensor)==HIGH)
  {
    led=!led;
  }
  digitalWrite(pinoled,led);
}

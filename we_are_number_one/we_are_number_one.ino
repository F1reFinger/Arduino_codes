const int fn = 400;
const int hn = 200;
const int qn = 100;
const int f5 = 698;
const int c6 = 1047;
const int b5 = 988;
const int gh5 = 831;
const int ch6 = 1109;
const int dh6 = 1245;

int song[] = {
  f5,fn + hn,
  c6,hn,
  b5,qn,
  c6,qn,
  b5,qn,
  c6,qn,
  b5,hn,
  c6,hn,
  gh5,fn,
  f5,fn + hn,
  f5,hn,
  gh5,hn,
  c6,hn,
  ch6,fn,
  gh5,fn,
  ch6,fn,
  dh6,fn,
  c6,hn,
  ch6,hn,
  c6,hn,
  ch6,hn,
  c6,fn
  };

void setup() {
  Serial.begin(9600);
}

void loop() {

for (int i = 0; i < (sizeof(song)/sizeof(int)); i = i + 2){
  tone(8, song[i]);
  delay(song[i + 1]);
}

noTone(8);
delay(1000);

}

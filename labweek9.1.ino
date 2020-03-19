const byte LED_PIN = 9;
const byte INT_PIN = 3;
volatile byte toggle = LOW;
int a = 1;

void setup(){
  pinMode(9, OUTPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), blink, RISING);
}

void loop(){
  digitalWrite(9, toggle);
  delay(a*1000);
  toggle = !toggle;
}

void blink(){
  a++;
  if(a>3)
    a = 1;
}

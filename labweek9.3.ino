#include <SPI.h>
bool toggle;
volatile int timer1 = 3200;
int CLK_PIN = 13; 
int LATCH_PIN = 10; 
int DATA_PIN = 11;
int a[10]=
{
   0b00111111, //0
   0b00000110, //1
   0b01011011, //2
   0b01001111, //3
   0b11100110, //4
   0b01101101, //5
   0b01111101, //6
   0b00100111, //7
   0b01111111, //8
   0b01101111, //9
};
int i = 1;

void setup(){
  noInterrupts(); 
  TCCR1A = 0;
  TCCR1B = 0; 
  TCNT1 = timer1;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop(){
}

ISR(TIMER1_OVF_vect){
  TCNT1 = timer1;
  spi_write1(a[i]);
  i++; 
  if(i>9)
    i = 0;
}

void spi_write1(unsigned char cData){
  shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, cData);
  digitalWrite(10, HIGH);
  digitalWrite(10, LOW);
}

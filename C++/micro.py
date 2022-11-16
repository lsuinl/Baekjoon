#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int pattern= 0;

ISR(INT2_vect)
{
pattern=(pattern+1)%8;
}

ISR(INT3_vect)
{
pattern=(pattern+4)%8;
}

void INIT_PORT(void)
{
DDRB = 0xFF;
PORTB = 0x01;
DDRD = 0x00;
PORTD = 0x00;
}

void INIT_INT23(void)
{
EIMSK |= 0x0C; //00001100
EICRA |= 0xF0; //11110000
sei();//추가
}

int main(void)
{
INIT_PORT();
INIT_INT23();

while(1){
    PORTB=(1<<pattern);
}
return 0;
}
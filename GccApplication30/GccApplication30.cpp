#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int num = 1;

ISR(INT2_vect)
{
	if (num == 1)
		num = 0;
	else
		num = 1;	
}

int main(void)
{
	sei();
	GIMSK |= (1<<INT1);
	MCUCR = (0<<ISC11) | (1<<ISC10);
	DDRD = 0xFF;
    while(1)
    {
        if (num == 1)
			PORTB |= 1;
		else
			PORTB &= ~1;
		_delay_ms(100);		
    }
	return 0;
}
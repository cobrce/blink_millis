#define F_CPU 9600000
#include <avr/io.h>
#include <util/delay.h>

#include "millis.h"

#define BLINK_INTERVAL 1000

millis_t PrevBlink = 0;
int main()
{
    DDRB = _BV(PB0);
    PORTB = 0;

    millis_init();
    sei();

    while (1)
    {
        millis_t now = millis();
        if ((now - PrevBlink) >= BLINK_INTERVAL)
        {
            PORTB ^= _BV(PB0);
            PrevBlink = now;
        }
    }
}

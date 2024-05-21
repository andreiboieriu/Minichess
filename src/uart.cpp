#include "uart.hpp"

#include <avr/io.h>

Uart::Uart() {
    init();
}

void Uart::init() {
    // set baud rate
    uint16_t value = UBRR115200;

    UBRR0L = (uint8_t)(value & 0xFF);
    UBRR0H = (uint8_t)(value >> 8);

    // enable rx and tx pins
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
}

void Uart::putc(unsigned char data) {
    // wait for transmit buffer to be empty
    while(!(UCSR0A & (1 << UDRE0)));

    // load data into transmit register
    UDR0 = data;
}

void Uart::puts(char* s)
{
    // transmit character until NULL is reached
    while(*s > 0) Uart::putc(*s++);
}

void Uart::putU8(uint8_t val)
{
    uint8_t dig1 = '0', dig2 = '0';

    // count value in 100s place
    while(val >= 100)
    {
        val -= 100;
        dig1++;
    }

    // count value in 10s place
    while(val >= 10)
    {
        val -= 10;
        dig2++;
    }

    // print first digit (or ignore leading zeros)
    if(dig1 != '0') Uart::putc(dig1);

    // print second digit (or ignore leading zeros)
    if((dig1 != '0') || (dig2 != '0')) Uart::putc(dig2);

    // print final digit
    Uart::putc(val + '0');
}

void Uart::putU16(uint16_t val)
{
    uint8_t dig1 = '0', dig2 = '0', dig3 = '0', dig4 = '0';

    // count value in 10000s place
    while(val >= 10000)
    {
        val -= 10000;
        dig1++;
    }

    // count value in 1000s place
    while(val >= 1000)
    {
        val -= 1000;
        dig2++;
    }

    // count value in 100s place
    while(val >= 100)
    {
        val -= 100;
        dig3++;
    }

    // count value in 10s place
    while(val >= 10)
    {
        val -= 10;
        dig4++;
    }

    // was previous value printed?
    uint8_t prevPrinted = 0;

    // print first digit (or ignore leading zeros)
    if(dig1 != '0') {Uart::putc(dig1); prevPrinted = 1;}

    // print second digit (or ignore leading zeros)
    if(prevPrinted || (dig2 != '0')) {Uart::putc(dig2); prevPrinted = 1;}

    // print third digit (or ignore leading zeros)
    if(prevPrinted || (dig3 != '0')) {Uart::putc(dig3); prevPrinted = 1;}

    // print third digit (or ignore leading zeros)
    if(prevPrinted || (dig4 != '0')) {Uart::putc(dig4); prevPrinted = 1;}

    // print final digit
    Uart::putc(val + '0');
}

unsigned char Uart::getc(void)
{
    // wait for data
    while(!(UCSR0A & (1 << RXC0)));

    // return data
    return UDR0;
}

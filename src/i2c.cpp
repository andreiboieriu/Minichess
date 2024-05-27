#include "i2c.hpp"

Twi::Twi() {
    init();
}

void Twi::init(void) {
	TWCR = 0;

    TWSR = (0b00 << TWPS0);
    TWBR = 2;
}

void Twi::start(void) {    
	TWCR = 0;
    
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);

	while (!(TWCR & (1 << TWINT)));
}

void Twi::write(uint8_t data) {
    TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);

    while (!(TWCR & (1<<TWINT)));
}

void Twi::stop(void) {
    // Send STOP condition
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTO);
}

void Twi::discover(uint8_t *found_address) {
    for (uint8_t i = 0x00; i < 0x7F; i++)  {
        Twi::start();

        Twi::write((i << 1) | 1);

        if (((TWSR & 0xF8) == TW_MR_SLA_ACK)) {
            *found_address = i;
            Twi::stop();
            return;
        }
    }

    Twi::stop();
}
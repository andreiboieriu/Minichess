#include "i2c.hpp"

Twi::Twi() {
    init();
}

void Twi::init(void) {
	/* reset control register */
	TWCR = 0;

    TWSR = (0b00 << TWPS0);
    // TWBR = 72;
    TWBR = 2;
}

void Twi::start(void) {    
    // Send START condition (using TWCR)
	TWCR = 0; /* reset it again, just to be sure */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	// obligatory: wait for START condition to be sent
	while (!(TWCR & (1 << TWINT)));
}

void Twi::write(uint8_t data) {
    // Send a byte of data (TWCR + TWDR)
    TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN) /* | (1 << TODO_ACKNOWLEDGE) */;
	// TODO 1: wait for transfer to complete (TWINT flag)
    while (!(TWCR & (1<<TWINT)));
}

void Twi::read_ack(uint8_t *data) {
    // TODO 1: Read a byte of data with ACK enabled 
	// TWCR ...
	// while ...
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
    *data = TWDR;
}

void Twi::read_nack(uint8_t *data) {
    // TODO 1: Read a byte of data with ACK disabled 
	// same as above, but don't send acknowledge
    TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
    *data = TWDR;
}

void Twi::stop(void) {
    // Send STOP condition
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTO);
}

void Twi::discover(uint8_t *found_address) {
    // TODO 2: Search for I2C slaves.
    // HINT: An acknowledged SLA_R should enable a flag in TWSR. Check the datasheet!
    for (uint8_t i = 0x00; i < 0x7F; i++)  {
        Twi::start();
		// TODO: write address & check TWSR (see util/twi.h documentation for
		// constants!)
        Twi::write((i << 1) | 1);
        // TWAR = i << 1;
        if (((TWSR & 0xF8) == TW_MR_SLA_ACK)) {
            *found_address = i;
            Twi::stop();
            return;
        }
    }

    Twi::stop();
}
#pragma once

#include <util/twi.h>

class Twi {
public:
    Twi();

    void start(void);
    void write(uint8_t data);
    void read_ack(uint8_t *data);
    void read_nack(uint8_t *data);
    void stop();
    void discover(uint8_t *found_address);

private:
    void init(void);
};

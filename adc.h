// TODO - the declarations of your library functions go here
#include "spi.h"
#define CS PB6
#define CS_PORT PORTB
#define CS_DDR DDRB
#define manual_channel 0x1800
void initialize();
uint16_t channel_to_raw(uint8_t channel);
double raw_to_voltage(uint16_t raw);

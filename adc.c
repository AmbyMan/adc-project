#include "adc.h"


// TODO - the implementations of your library functions go here

void initialize()//complete
{
  init_spi();
  init_cs(CS &CS_DDR);
  set_cs_high(CS, &CS_PORT);
}

uint16_t channel_to_raw(uint8_t channel)
{
  // a function that takes a channel number as a parameter, reads data, returns 12-bit value
  uint16_t x = channel;
  x = x << 7;
  x =  manual_channel | x;


  uint16_t raw = 0xFFFF;

  while (raw >> 12 != channel)
  {
    set_cs_low(CS, &CS_PORT);
    raw = send_spi(x >> 8);
    raw = raw << 8;
    raw = raw | send_spi(x);
    set_cs_high(CS, &CS_PORT);
  }

  raw = raw & 0x0FFF;
  return raw;
}

double raw_to_voltage(uint16_t raw)//complete
{
  double voltage = (double) raw*2.5/4096;
  return voltage;
}

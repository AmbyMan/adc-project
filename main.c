#include "adc.h"


int main(void)
{
  initialize();
  while (1)
  {
    for (int i = 0; i <= 11; i++)
    {

      uint16_t x = channel_to_raw(i);
      double v = raw_to_voltage(x);
      printf("test value: %d, voltage: %f", x, v);
    }
  }




    return 0;
}

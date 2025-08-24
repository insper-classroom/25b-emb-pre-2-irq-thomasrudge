#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int led = 4;
const int botao = 28;
volatile int check = 0;

void btn_callback(uint gpio , uint32_t events){
  if (events == 0x4){ // falling edge
      check = 1;
  }
  else if(events == 0x8){
    check=0;
  }

}

int main() {
  stdio_init_all();
  gpio_init(led);
  gpio_init(botao);

  gpio_set_dir(led, GPIO_OUT);
  gpio_set_dir(botao, GPIO_IN);

  gpio_pull_up(botao);

  gpio_set_irq_enabled_with_callback(
      botao, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &btn_callback);


  while (true) {
    gpio_put(led, check);
  }
}

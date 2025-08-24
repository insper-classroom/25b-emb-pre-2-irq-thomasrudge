#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int led_g = 6;
const int led_r = 4;
const int botao_g = 26;
const int botao_r = 28;

volatile int check_g = 0;
volatile int check_r = 0;

void btn_callback(uint gpio , uint32_t events){
  if (gpio == botao_g){ 
    if (events == 0x8){
      check_g = !check_g;
    }
      
  }


  else if (gpio == botao_r){ 
    if (events == 0x4){
      check_r = !check_r;
    }
      
  }
  
}

int main() {
  stdio_init_all();

  gpio_init(led_g);
  gpio_init(led_r);
  gpio_init(botao_g);
  gpio_init(botao_r);

  gpio_set_dir(led_g, GPIO_OUT);
  gpio_set_dir(botao_r, GPIO_IN);
  gpio_set_dir(led_r, GPIO_OUT);
  gpio_set_dir(botao_g, GPIO_IN);

  gpio_pull_up(botao_r);
  gpio_pull_up(botao_g);

  gpio_set_irq_enabled_with_callback(botao_r,
    GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,
    true,
    &btn_callback);

  gpio_set_irq_enabled(botao_g,
    GPIO_IRQ_EDGE_FALL,
    true);

  while (true) {
    gpio_put(led_g, check_g);
    gpio_put(led_r, check_r);
  }
}

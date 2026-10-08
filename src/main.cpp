#include <Arduino.h>
#include "hardware.h"
#include "game.h"

int main(void) {
  init();

  hardware_init();

  while (1) {
    game();
  }
}
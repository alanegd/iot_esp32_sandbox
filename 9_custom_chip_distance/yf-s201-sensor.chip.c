// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // TODO: Put your chip variables here
  pin_t pin_out;
  pin_t pin_vcc;
  pin_t pin_gnd;

  float frequency_attr;
  uint32_t range_attr;

} chip_state_t;

// Pre-declare Timer Event
static void chip_timer_event(void *user_data); // IMPORTANTE

void chip_init() {
  // Chip state configuration
  chip_state_t *chip = malloc(sizeof(chip_state_t)); // IMPORATANTE

  chip->pin_out = pin_init("OUT", ANALOG);
  chip->pin_vcc = pin_init("VCC", INPUT_PULLDOWN);
  chip->pin_gnd = pin_init("GND", INPUT_PULLUP);

  chip->frequency_attr = attr_init("frequency", 10.0); // 10 es mi valor por defecto
  chip->range_attr = attr_init("state", 0); // 0 es mi valor por defecto

  // Timer Event Configuration
  const timer_config_t timer_config = { // IMPORTANTE
    .callback = chip_timer_event,
    .user_data = chip,
  };

  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 10000, true); // 10,000 microseconds = 10ms, TRUE = repetitive

  printf("Custom Chip Initialized\n");
}

void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;

  int current_state = attr_read(chip->range_attr);
  float current_frequency = attr_read_float(chip->frequency_attr);

  printf("Current state: %d", current_state);
  printf("\n");
  printf("Current frequency: %f", current_frequency);

  if (current_state == 0) {
    pin_dac_write(chip->pin_out, 0.0);
    return;
  }

  float voltage = (attr_read_float(chip->frequency_attr))*5.0/187.5;

  if (pin_read(chip->pin_vcc) && !pin_read(chip->pin_gnd)) {
    printf("Generando pulsos");
    pin_dac_write(chip->pin_out, voltage);
  }
}

// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

// Chip State Values
typedef struct {
  pin_t pin_out;
  pin_t pin_vcc;
  pin_t pin_gnd;

  uint32_t moisture_attr;
  uint32_t threshold_attr; 
} chip_state_t;

// Pre-declare Timer Event
static void chip_timer_event(void *user_data);

void chip_init() {
  // Chip State Configuration
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  if (!chip) {
    return;
  }

  // Setup Chip Pins

  // 'pin_init' busca un pin por su nombre y define cómo se usará.
  // Aquí, PIN_OUT será un pin de SALIDA DIGITAL, inicializado en BAJO (LOW).
  chip->pin_out = pin_init("OUT", OUTPUT_LOW);
  chip->moisture_attr = attr_init("moisture", 10.0); // 10 as default value
  chip->threshold_attr = attr_init("threshold", 50); // 50 as default value
  chip->pin_vcc = pin_init("VCC", INPUT_PULLDOWN);
  chip->pin_gnd = pin_init("GND", INPUT_PULLUP);  

  // Timer Event Configuration
  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };

  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 10000, true); // 10,000 microseconds = 10ms, TRUE = repetitive

  printf("Custom Capacitive Sensor Initialized\n");
}

// Timer Event Handler (Called every 10 miliseconds)
void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;

  // Read the current moisture value from the slider (0-100)
  float current_moisture = attr_read_float(chip->moisture_attr);
  int current_threshold = attr_read(chip->threshold_attr);

  if (current_moisture > current_threshold) {
    pin_write(chip->pin_out, HIGH);
    printf("Threshold Exceeded\n");
  } else {
    pin_write(chip->pin_out, LOW);
  }
}
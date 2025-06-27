#include "LcdDisplay.h"
#include <Arduino.h>

LcdDisplay::LcdDisplay(uint8_t address, uint8_t cols, uint8_t rows)
    : Actuator(0), lcd(address, cols, rows) {}

void LcdDisplay::init() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void LcdDisplay::clear() {
  lcd.clear();
}

void LcdDisplay::displayData(float temp, float hum) {
    lcd.clear();
    
    char tempLine[17];

    snprintf(tempLine, sizeof(tempLine), "Temp: %.1f C", temp);
    
    char humLine[17];

    snprintf(humLine, sizeof(humLine), "Hum:  %.1f %%", hum);

    lcd.setCursor(0, 0);
    lcd.print(tempLine);
    
    lcd.setCursor(0, 1);
    lcd.print(humLine);
}
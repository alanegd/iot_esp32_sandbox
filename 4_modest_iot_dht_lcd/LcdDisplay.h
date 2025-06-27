#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <LiquidCrystal_I2C.h>
#include "Actuator.h"

class LcdDisplay : public Actuator {
public:
    /**
     * @brief Constructs an LcdDisplay actuator.
     * @param address The I2C address of the LCD.
     * @param cols The number of columns.
     * @param rows The number of rows.
     */
    LcdDisplay(uint8_t address, uint8_t cols, uint8_t rows);

    /**
     * @brief Initializes the LCD.
     */
    void init();

    /**
     * @brief Displays the temperature and humidity data.
     * @param temp The temperature value to display.
     * @param hum The humidity value to display.
     */
    void displayData(float temp, float hum);

    /**
     * @brief Clears the LCD screen.
     */
    void clear();

private:
    LiquidCrystal_I2C lcd;
};

#endif // LCD_DISPLAY_H
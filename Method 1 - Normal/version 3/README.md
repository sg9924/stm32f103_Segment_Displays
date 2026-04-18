# Version 3

- added support for Multi Digit Displays
- Simultaneous Digit Driving not yet implemented


## APIs

| API Name | Inputs | Outputs | Description |
| --- | --- | --- | --- |
| seg_pin_configure | segments_t* segment_pins, GPIO_RegDef* GPIO_Port | none | Configures the GPIO pins used for the segments |
| seg_digit_pin_configure | digits_t* digit_pins, GPIO_RegDef* GPIO_Port | none | Configures the GPIO Pins used for selecting the digits |
| seg_configure | segments_t* segment_pins, GPIO_RegDef* Seg_GPIO, digits_t* digit_pins, GPIO_RegDef* Digit_GPIO | none | Configures all the GPIO pins for the segment display |
| seg_pin_init |  | none | Initializes the segment GPIO pins |
| seg_digit_init |  | none | Initializes the digit select GPIO pins |
| seg_init | none | none | Initializes all the GPIO pins for the segment display |
| seg_pins_reset | none | none | Resets all segments of the display |
| seg_digit_reset | none | none | Resets the digit select pins of the display |
| seg_digit_select | uint8_t digit_pin | none | Used to select a certain digit of the display |
| seg_display | uint8_t character, uint8_t decimal | none | Displays the character provided with an option to include the H segment (decimal point) |
| seg_display_digit | uint8_t character, uint8_t digit_pin, uint8_t decimal | none | Select the provided digit and displays the provided character in the segment display |


## API Parameters:

- `segments_t`: structure which holds the GPIO pin numbers of each segment
- `digits_t`: structure which holds the GPIO pin numbers of the digit select pins
- `GPIO_RegDef*`: Starting Address of the GPIO Port. Found in `stm32f103xx_gpio.h`
- `character`: character to be displayed: `'0'` to `'9'`
- `decimal`: option to include H segment: `NO_DECIMAL` or `DECIMAL`, found in `seg_display.h`
- `digit_pin`: the GPIO pin number of a specific digit select pin 
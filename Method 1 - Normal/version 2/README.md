# Version 2

- added support for Common Anode displays


## APIs

| API Name | Inputs | Outputs | Description |
| --- | --- | --- | --- |
| seg_pin_configure | segments_t* segment_pins, GPIO_RegDef* GPIO_Port | none | Configures the GPIO pins used for the segments |
| seg_init | none | none | Initializes the GPIO pins |
| seg_pins_reset | none | none | Resets all segments of the display |
| seg_display | uint8_t character, uint8_t decimal | none | Displays the character provided with an option to include the H segment (decimal point) |


## API Parameters:

- `segments_t`: structure which holds the pin numbers of each segment
- `GPIO_RegDef*`: Starting Address of the GPIO Port. Found in `stm32f103xx_gpio.h`
- `character`: character to be displayed: `'0'` to `'9'`
- `decimal`: option to include H segment: `NO_DECIMAL` or `DECIMAL`, found in `seg_display.h`
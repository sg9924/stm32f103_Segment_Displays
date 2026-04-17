#include"stm32f103xx_init.h"
#include"stm32f103xx_gpio.h"
#include"stm32f103xx_systick.h"
#include"seg_display.h"


int main()
{
    board_init();

    segments_t seg_pins = {GPIO_PIN7, GPIO_PIN9, GPIO_PIN0, GPIO_PIN5, GPIO_PIN10, GPIO_PIN8, GPIO_PIN4, GPIO_PIN1};
    digits_t digit_pins = {GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8};

    seg_configure(&seg_pins, GPIOA, &digit_pins, GPIOB);
    seg_init();
    seg_digit_select(digit_pins.DIGIT_1);

    while(1)
	{
        for(uint8_t c='0'; c<='9'; c++)
        {
            seg_display(c, WITH_DECIMAL);
            Systick_delay(1000);
        }        
    }
    return 0;
}
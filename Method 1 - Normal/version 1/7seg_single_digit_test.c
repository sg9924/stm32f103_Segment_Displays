#include"stm32f103xx_init.h"
#include"stm32f103xx_gpio.h"
#include"stm32f103xx_systick.h"
#include"seg_display.h"




GPIO_Handle G;
SevSeg_Handle S;

int main()
{
    board_init();

    segments_t seg_pins = {GPIO_PIN7, GPIO_PIN9, GPIO_PIN0, GPIO_PIN5, GPIO_PIN10, GPIO_PIN8, GPIO_PIN4, GPIO_PIN1};
    seg_pin_configure(&S, &seg_pins, GPIOA);
    seg_init(&S, &G);
    
    while(1)
	{
        for(uint8_t c='0'; c<='9'; c++)
        {
            seg_display(GPIOA, &seg_pins, c);
            Systick_delay(1000);
        }
    }
    return 0;
}
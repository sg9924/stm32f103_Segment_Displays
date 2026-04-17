#ifndef SEGDISPLAY_H
#define SEGDISPLAY_H

#include"stm32f103xx.h"
#include"stm32f103xx_gpio.h"
#include"stm32f103xx_utilities.h"
#include"seg_3461BS.h"


typedef struct
{
    uint8_t seg_A;
    uint8_t seg_B;
    uint8_t seg_C;
    uint8_t seg_D;
    uint8_t seg_E;
    uint8_t seg_F;
    uint8_t seg_G;
    uint8_t seg_H;
}segments_t;

typedef struct
{
    uint8_t DIGIT_1;
    uint8_t DIGIT_2;
    uint8_t DIGIT_3;
    uint8_t DIGIT_4;
}digits_t;

typedef struct
{
    GPIO_RegDef* Seg_GPIO_Port;
    GPIO_RegDef* Digit_GPIO_Port;
    GPIO_Handle* pGPIOHandle;
    segments_t*  segs;
    digits_t*    digits;
    uint8_t      conn_type;
    uint8_t      display_type;
    uint8_t      selected_digit;
}SevSeg_Handle;


#define NO_DECIMAL               0
#define WITH_DECIMAL             1


void seg_pin_configure(segments_t* segment_pins, GPIO_RegDef* GPIO_Port);
void seg_digit_pin_configure(digits_t* digit_pins, GPIO_RegDef* GPIO_Port);
void seg_configure(segments_t* segment_pins, GPIO_RegDef* Seg_GPIO, digits_t* digit_pins, GPIO_RegDef* Digit_GPIO);

void seg_pin_init();
void seg_digit_init();
void seg_init();

void seg_pins_reset();
void seg_digit_reset();

void seg_digit_select(uint8_t digit_pin);
void seg_display(uint8_t character, uint8_t decimal);
void seg_display_digit(uint8_t character, uint8_t digit_pin, uint8_t decimal);


#endif
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
    GPIO_RegDef* Seg_GPIO_Port;
    GPIO_Handle* pGPIOHandle;
    segments_t*  segs;
    uint8_t      conn_type;
    uint8_t      display_type;
}SevSeg_Handle;


#define NO_DECIMAL               0
#define WITH_DECIMAL             1


void seg_pin_configure(segments_t* segment_pins, GPIO_RegDef* GPIO_Port);
void seg_init();
void seg_pins_reset();
void seg_display(uint8_t character, uint8_t decimal);


#endif
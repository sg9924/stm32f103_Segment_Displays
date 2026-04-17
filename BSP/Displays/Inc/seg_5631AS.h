#ifndef SEG5631AS_H
#define SEG5631AS_H


/*
--Segment Pins
#define SEG_A        SEG_PIN11
#define SEG_B        SEG_PIN7
#define SEG_C        SEG_PIN4
#define SEG_D        SEG_PIN2
#define SEG_E        SEG_PIN1
#define SEG_F        SEG_PIN10
#define SEG_G        SEG_PIN5
#define SEG_H        SEG_PIN3
*/


/*
-- Recommended GPIO Mapping
-- when not using driver ICs
segments_t seg_pins = {GPIO_PIN7, GPIO_PIN9, GPIO_PIN0, GPIO_PIN5, GPIO_PIN10, GPIO_PIN8, GPIO_PIN4, GPIO_PIN1};
*/


#define SEG_CONNECTION_TYPE     SEG_COMMON_ANODE
#define SEG_DISPLAY_TYPE        SEG_SINGLE_DIGIT
#define NO_OF_SEGMENTS          7
#define DECIMAL_POINT           1
#define NO_OF_DIGITS            1

#endif /*SEG5631AS_H*/
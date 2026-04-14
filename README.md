# stm32f103_Segment_Displays

This repository contains drivers required for interfacing the STM32 Blue Pill with 7 segment displays.

There are various methods for driving the seven segment displays. This repo provides drivers for each method with multiple versions for a specific method starting from the simplest one till the latest with each successive version adding more features, improvements or optimizations.

This repo can be useful for anyone getting starting with seven segment dsiplays.
This is not limited to the blue pill. This can provide a reference for other boards also.

Note:
- No HAL Device Drivers has been used here for the STM32 Blue Pill board. The Device Drivers used here are custom.
- You can replace the Driver Functions with HAL functions in the Segment Display Drivers.
- Documentations for each version will be provided in the future.
- This README is incomplete and will be updated in the future.


# Driver Details

## Method 1:
- The usual method - just use the GPIo of the board
- no external driver ICs

## Method 2:
- Shift Registers - specifically the most common/popular one: 74HC595


# Future:
- provide drivers for using MAX7219, TM1637/1638


# Tools Used:
- Make: 
- GDB: 
- st-tools:


# Board Details:
- STM32F103 also known as the Blue Pill



Note:
- No AI has been used in generating any of the code provided here.
- The code provided here is in no way perfect or optimized, but it does the job.
- I have created this repo for my learning and it may help others who are beginners.
- The code has been organized for multiple versions as I wanted to look back and see how they were developed from the very basic to more complex logic.

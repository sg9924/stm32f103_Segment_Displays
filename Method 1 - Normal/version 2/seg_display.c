#include<stdint.h>
#include"seg_display.h"
#include"stm32f103xx_init.h"

static SevSeg_Handle S;
static GPIO_Handle G;

void seg_pin_configure(segments_t* segment_pins, GPIO_RegDef* GPIO_Port)
{
	S.conn_type     = SEG_CONNECTION_TYPE;
	S.display_type  = SEG_DISPLAY_TYPE;
	S.segs          = segment_pins;
	S.Seg_GPIO_Port = GPIO_Port;
}


void seg_init()
{
	S.pGPIOHandle = &G;

	GPIO_Config(S.pGPIOHandle, S.Seg_GPIO_Port, GPIO_MODE_OP, GPIO_CONFIG_GP_OP_PP, S.segs->seg_A, GPIO_OP_SPEED_10);
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_B;
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_C;
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_D;
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_E;
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_F;
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_G;
	GPIO_Init(S.pGPIOHandle);
	
	S.pGPIOHandle->GPIOx_PinConfig.PinNo = S.segs->seg_H;
	GPIO_Init(S.pGPIOHandle);

	seg_pins_reset(S.Seg_GPIO_Port, S.segs);
}


void seg_pins_reset()
{
	if(S.conn_type == SEG_COMMON_CATHODE)
	{
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_A);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_B);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_C);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_D);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_E);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_F);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_G);
		GPIO_BIT_RESET(S.Seg_GPIO_Port, S.segs->seg_H);
	}
	else if(S.conn_type == SEG_COMMON_ANODE)
	{
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_A);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_B);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_C);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_D);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_E);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_F);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_G);
		GPIO_BIT_SET(S.Seg_GPIO_Port, S.segs->seg_H);
	}
}



void seg_display(uint8_t character, uint8_t decimal)
{
	uint16_t port_reset_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F | 1<<S.segs->seg_G | 1<<S.segs->seg_H);
	uint16_t port_value;

	if(character == '0')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '1')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_B | 1<<S.segs->seg_C);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_B | 1<<S.segs->seg_C));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '2')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_G | 1<<S.segs->seg_D | 1<<S.segs->seg_E);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_G | 1<<S.segs->seg_D | 1<<S.segs->seg_E));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '3')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_G);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_G));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '4')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_F | 1<<S.segs->seg_G);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_F | 1<<S.segs->seg_G));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '5')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_F | 1<<S.segs->seg_G);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_F | 1<<S.segs->seg_G));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '6')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F | 1<<S.segs->seg_G);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F | 1<<S.segs->seg_G));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '7')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '8')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F | 1<<S.segs->seg_G);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_E | 1<<S.segs->seg_F | 1<<S.segs->seg_G));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}

	if(character == '9')
	{
		if(S.conn_type == SEG_COMMON_CATHODE)
		{
			port_value = (1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_F | 1<<S.segs->seg_G);
			if(decimal == WITH_DECIMAL)
				port_value |= (1<<S.segs->seg_H);
		}
		else if(S.conn_type == SEG_COMMON_ANODE)
		{
			port_value = ((port_reset_value) & ~(1<<S.segs->seg_A | 1<<S.segs->seg_B | 1<<S.segs->seg_C | 1<<S.segs->seg_D | 1<<S.segs->seg_F | 1<<S.segs->seg_G));
			if(decimal == WITH_DECIMAL)
				port_value &= ~(1<<S.segs->seg_H);
		}
		GPIO_WriteOpPort(S.Seg_GPIO_Port, port_value);
	}
}
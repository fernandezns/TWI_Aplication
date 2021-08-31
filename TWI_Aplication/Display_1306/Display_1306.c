/*
 * Display_1306.c
 *
 * Created: 27/8/2021 11:18:43
 *  Author: Nicolás
 */ 
#include "Display_1306.h"


void disply1306InitTWI(uint8_t micro){
	#if	(micro&ATMEGA328P)
		TWBR=((F_CPU/SCL_CLOCK)-16)/2;			//Factor de division del bitrate generator = 32
		TWSR&=~(1<<TWPS0);						//TWI Prescaler = 1
		TWSR&=~(1<<TWPS1);						//TWI Prescaler = 1
		TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN)|(1<<TWIE);		 
	#endif
}

void disply1306SlaveAddrsTWI(uint8_t micro){
	#if	(micro&ATMEGA328P)
		TWDR=0x78;
		TWCR=((1<<TWINT)|(1<<TWEN));
	#endif	
}

void disply1306Data(uint8_t micro,uint8_t data){
	#if	(micro&ATMEGA328P)	
		TWDR=data;
	#endif
}

void disply1306StopTWI(uint8_t micro){
	#if (micro&ATMEGA328P)
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	#endif
}
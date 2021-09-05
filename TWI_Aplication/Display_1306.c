/*
 * Display_1306.c
 *
 * Created: 27/8/2021 11:18:43
 *  Author: Nicolás
 */
#include "Display_1306/FONT1.h"
#include "Display_1306/Display_1306.h"

static uint8_t twi_Status=0;
static uint8_t comando=0;
const uint8_t texto[]={'H','O','L','A',' ','M','U','N','D','O'};

void twiInterrupt(){
	twi_Status=TWSR&0xF8;
}

uint8_t disply1306Write(uint8_t page,uint8_t cantLetras){
	static uint8_t write=0,k=0,j=0;
	uint8_t caracter=0;
	
	switch(twi_Status){
		case 0:
			twi_Status=1;
			disply1306InitTWI(ATMEGA328P);
			break;
		case TWI_STARTED:
			twi_Status=1;
			disply1306SlaveAddrsTWI(ATMEGA328P);
			break;
		case SLA_W_SENT: case DATA_RECEIVED: 
			twi_Status=1;
			write=1;
			break;
	}

	if(write){
		write=0;
		switch(comando){
			case 0:
				disply1306Data(ATMEGA328P,0x80);
				comando++;
				break;	
			case 1:
				disply1306Data(ATMEGA328P,page);
				comando++;
				break;
			case 2:
				disply1306Data(ATMEGA328P,0x40);
				comando++;
				break;
			case 3:
				if(k<cantLetras){
					caracter=pgm_read_byte_near(&ROMCHAR[texto[k]*8+j]);
					disply1306Data(ATMEGA328P,caracter);
					j++;
					if(j==8){
						k++;
						j=0;
					}
				}
				else{
					comando=0;
					disply1306StopTWI(ATMEGA328P);
					twi_Status=0;
					return 1;
				}
				break;
		}
	}
	return 0;
}

uint8_t disply1306DefaultInit(){
	switch(twi_Status){
		case 0:
			twi_Status=1;
			disply1306InitTWI(ATMEGA328P);
			break;
		case TWI_STARTED:
			twi_Status=1;
			disply1306SlaveAddrsTWI(ATMEGA328P);
			break;
		case SLA_W_SENT: case DATA_RECEIVED: 
			twi_Status=1;
			disply1306Settings();
			if(comando==LAST_COMAND_RECEIVED){
				disply1306StopTWI(ATMEGA328P);
				comando=0;
				twi_Status=0;
				return 1;
			}
			break;
	}
	return 0;
}
void disply1306Settings(){		
	switch(comando){
		case 0:
			disply1306Data(ATMEGA328P,CTRL_BYTE_COMANDO);
			comando++;
			break;
		case 1:
			disply1306Data(ATMEGA328P,DISPLAY_OFF);
			comando++;
			break;
		case 2:
			disply1306Data(ATMEGA328P,CLK_DIVR_OSC_FREQ);
			comando++;
			break;
		case 3:
			disply1306Data(ATMEGA328P,0x80);
			comando++;
			break;
		case 4:
			disply1306Data(ATMEGA328P,MPLX_NUMBER);
			comando++;
			break;
		case 5:
			disply1306Data(ATMEGA328P,0x3F);
			comando++;
			break;
		case 6:
			disply1306Data(ATMEGA328P,DISPLAY_OFFSET);
			comando++;
			break;
		case 7:
			disply1306Data(ATMEGA328P,0);
			comando++;
			break;
		case 8:
			disply1306Data(ATMEGA328P,RAM_STARTLINE_REG);
			comando++;
			break;
		case 9:
			disply1306Data(ATMEGA328P,CHARGE_PUMP);
			comando++;
			break;
		case 10:
			disply1306Data(ATMEGA328P,0x14);
			comando++;
			break;
		case 11:
			disply1306Data(ATMEGA328P,SEGMENT_REMAP);
			comando++;
			break;
		case 12:
			disply1306Data(ATMEGA328P,COM_OUT_SCAN_DIR);
			comando++;
			break;
		case 13:
			disply1306Data(ATMEGA328P,COM_PINS_CONFIG);
			comando++;
			break;
		case 14:
			disply1306Data(ATMEGA328P,0x12);
			comando++;
			break;
		case 15:
			disply1306Data(ATMEGA328P,CONTRAST);
			comando++;
			break;
		case 16:
			disply1306Data(ATMEGA328P,0x9F);
			comando++;
			break;
		case 17:
			disply1306Data(ATMEGA328P,MEMORY_ADRESS_MODE);
			comando++;
			break;
		case 18:
			disply1306Data(ATMEGA328P,0x02);//Memory Addressing Mode (Horizontal=0 , Vertical=1 , Page=2)
			comando++;
			break;
		case 19:	
			disply1306Data(ATMEGA328P,DISABLE_SCROLL);
			comando++;
			break;	
		case 20:
			disply1306Data(ATMEGA328P,PRE_CHARGE_PERIOD);
			comando++;
			break;
		case 21:
			disply1306Data(ATMEGA328P,0x22);
			comando++;
			break;
		case 22:
			disply1306Data(ATMEGA328P,VCOMH_DESELECT_LEVEL);
			comando++;
			break;
		case 23:
			disply1306Data(ATMEGA328P,0x40);
			comando++;
			break;
		case 24:
			disply1306Data(ATMEGA328P,RESUME_TO_RAM);
			comando++;
			break;
		case 25:
			disply1306Data(ATMEGA328P,DISPLAY_INVERSE_MODE);
			comando++;
			break;
		case 26:
			disply1306Data(ATMEGA328P,DISPLAY_ON);
			comando++;
			break;
		case 27:
			comando=LAST_COMAND_RECEIVED;
			break;
	}
}



uint8_t cleanPage(uint8_t page){
	static uint8_t clean=0,i=0;
	switch(twi_Status){
		case 0:
			twi_Status=1;
			disply1306InitTWI(ATMEGA328P);
			break;
		case TWI_STARTED:
			twi_Status=1;
			disply1306SlaveAddrsTWI(ATMEGA328P);
			break;
		case SLA_W_SENT: case DATA_RECEIVED: 
			twi_Status=1;
			clean=1;
			break;
	}
	if(clean){
		clean=0;
		switch(comando){
			case 0:
				disply1306Data(ATMEGA328P,0x80);
				comando++;
				break;	
			case 1:
				disply1306Data(ATMEGA328P,page);
				comando++;
				break;
			case 2:
				disply1306Data(ATMEGA328P,0x40);
				comando++;
				break;
			case 3:
				if(i<128){
					disply1306Data(ATMEGA328P,0x00);
					i++;
				}
				else{
					i=0;
					disply1306StopTWI(ATMEGA328P);
					comando=0;
					twi_Status=0;
					return 1;
				}
				break;
		}
	}
	return 0;
}

uint8_t cleanAllDisplay(){
	static uint8_t page=0;
	switch(page){
		case 0:
			if(cleanPage(0xB0))
				page++;
			break;
		case 1:
			if(cleanPage(0xB1))
				page++;
			break;
		case 2:
			if(cleanPage(0xB2))
				page++;
			break;
		case 3:
			if(cleanPage(0xB3))
				page++;
			break;
		case 4:
			if(cleanPage(0xB4))
				page++;
			break;
		case 5:
			if(cleanPage(0xB5))
				page++;
			break;	
		case 6:
			if(cleanPage(0xB6))
				page++;
			break;
		case 7:
			if(cleanPage(0xB7)){
				page=0;
				return 1;
			}
			break;
	}
	return 0;
}



uint8_t disply1306InitTWI(uint8_t micro){
	if	(micro==ATMEGA328P){
		TWBR=((16000000UL/SCL_CLOCK)-16)/2;			//Factor de division del bitrate generator = 32
		TWSR&=~((1<<TWPS0)|(1<<TWPS1));						//TWI Prescaler = 1
		TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN)|(1<<TWIE);
		return 1;
	}	
	return 0;
}

uint8_t disply1306SlaveAddrsTWI(uint8_t micro){
	if(micro==ATMEGA328P){
		TWDR=SLAVE_WRITE;
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWIE);
		return 1;
	}
	return 0;
}

uint8_t disply1306Data(uint8_t micro,uint8_t data){
	if(micro==ATMEGA328P){
		TWDR=data;
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWIE);
		return 1;
	}
	return 0;
}

uint8_t disply1306StopTWI(uint8_t micro){
	if(micro==ATMEGA328P){
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
		return 1;
	}
	return 0;
}
/*
 * TWI_Aplication.c
 *
 * Created: 24/8/2021 08:23:22
 * Author : Nicolás
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include "Display_1306/Display_1306.h"
#include "Display_1306/FONT2.h"
 
 //Definiciones
#define ATMEGA328P	1
#define SCL_CLOCK 100000UL
#define DISPLAY_HEIGHT 64 //display 64pixls x 128 pixls
#define DISPLAY_WIDTH 128 //display 64pixls x 128 pixls
#define TWI_STARTED 0x08
#define TWI_RESTARTED 0x10
#define SLA_W_SENT	0x18
#define DATA_RECEIVED	0x28
#define NACK_RECEIVED 	0x30
#define LAST_COMAND_RECEIVED	0xF0
#define SLAVE_WRITE	(0x3C<<1)
#define SLAVE_READ  (0x3C<<1)|(0x01)

#define CTRL_BYTE_COMANDO 0
#define CTRL_BYTE_DATO 0x40
#define DISPLAY_OFF	0xAE
#define DISPLAY_ON 0xAF
#define CLK_DIVR_OSC_FREQ	0xD5// Display clock divide ratio & Oscillator frequency
#define MPLX_NUMBER	0xA8//Set Multiplex number(activated rows): ( range 16 ~ 64 )
#define DISPLAY_OFFSET	0xD3
#define RAM_STARTLINE_REG	0x40//Set display RAM start line register
#define CHARGE_PUMP	0x8D
#define SEGMENT_REMAP	0xA1 //SEG (columns) normal(0xA0) mode, (inverse=0xA1)
#define	COM_OUT_SCAN_DIR 0xC8 //COM (rows) normal mode(0xC0), (inverse=0xC8)
#define COM_PINS_CONFIG	0xDA//Set COM Pins Hardware config
#define CONTRAST	0x81	//Set Contrast Control
#define	MEMORY_ADRESS_MODE	0x20 //Memory Addressing Mode
#define DISABLE_SCROLL 0x2E
#define PRE_CHARGE_PERIOD	0xD9 //Pre-charge period
#define VCOMH_DESELECT_LEVEL	0xDB
#define	DISPLAY_NORMAL_MODE 0xA6
#define	DISPLAY_INVERSE_MODE 0xA7
#define ENTIRE_DISPLAY_ON 0xA5
#define	RESUME_TO_RAM 0xA4


//Prototipos de Funciones
void disply1306InitTWI(uint8_t micro);
void disply1306SlaveAddrsTWI(uint8_t micro);
void disply1306Data(uint8_t micro,uint8_t data);
void disply1306StopTWI(uint8_t micro);
void initPorts();
void writeDisplay();
void disply1306Settings();
void disply1306DefaultInit();
void disply1306Write(uint8_t page,uint8_t cantLetras);
void cleanAllDisplay();
uint8_t cleanPage(uint8_t page);

//Variables Globales
volatile uint8_t twi_Status=0;
volatile uint8_t flagInterrup=0;
uint8_t comando=0;
uint8_t tarea=0;
uint8_t texto[]={'H','O','L','A',' ','M','U','N','D','O'};



ISR(TWI_vect){ 
	flagInterrup=1;
	twi_Status=TWSR&0xF8;
}

void initPorts(){
	//Configuro PIN del LED como salida (PB5 Arduino UNO)
	DDRB = (1 << DDB5);
	//PORTB |= (1<<PORTB5);//encender LED 
	//
	//Configuro PIN 2 digital como entrada digital
	//DDRD &= ~(1<<DDD2);
	//PORTD &=~ (1<<PORTD2);
	//
}



int main(void)
{
	cli();
	initPorts();
	sei();
	_delay_ms(1000);
	flagInterrup=1;
    while (1) 
    {
		if(flagInterrup){
			flagInterrup=0;
			switch(tarea){
				case 0:
					disply1306DefaultInit();
					break;
				case 1:
					cleanAllDisplay();
					break;
				case 2:
					//disply1306Write(0xB2,10);
					disply1306Write(0xB0,10);
					break;
			}
		}
	}
}

void disply1306Write(uint8_t page,uint8_t cantLetras){
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
					flagInterrup=1;
					disply1306StopTWI(ATMEGA328P);
					twi_Status=0;
					tarea++;
				}
				break;
		}
	}
}

void disply1306DefaultInit(){
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
				tarea++;
				flagInterrup=1;
				twi_Status=0;
			}
			break;
	}
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
					flagInterrup=1;
					return 1;
				}
				break;
		}
	}
	return 0;
}

void cleanAllDisplay(){
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
				tarea++;
				page=0;
				flagInterrup=1;
			}
			break;
	}
}



void disply1306InitTWI(uint8_t micro){
	if	(micro==ATMEGA328P){
		TWBR=((F_CPU/SCL_CLOCK)-16)/2;			//Factor de division del bitrate generator = 32
		TWSR&=~((1<<TWPS0)|(1<<TWPS1));						//TWI Prescaler = 1
		TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN)|(1<<TWIE);
	}	
}

void disply1306SlaveAddrsTWI(uint8_t micro){
	if(micro==ATMEGA328P){
		TWDR=SLAVE_WRITE;
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWIE);
	}
}

void disply1306Data(uint8_t micro,uint8_t data){
	if(micro==ATMEGA328P){
		TWDR=data;
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWIE);
	}
}

void disply1306StopTWI(uint8_t micro){
	if(micro==ATMEGA328P){
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	}
}
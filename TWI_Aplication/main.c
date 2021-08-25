/*
 * TWI_Aplication.c
 *
 * Created: 24/8/2021 08:23:22
 * Author : Nicolás
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 

//definiciones
#define SCL_CLOCK 100000L
#define DISPLAY_HEIGHT 64 //display 64pixls x 128 pixls
#define DISPLAY_WIDTH 128 //display 64pixls x 128 pixls
#define TWI_STARTED 0x08
#define SLA_W_SENT	0x18
#define SLAVE_WRITE	(0x3C<<1)
#define SLAVE_READ  (0x3C<<1)|(0x01)
#define DATA_SENT	0x28

//Prototipos
void initPorts();
void startTWI();
void sendSlaveAdress();
void dataToTWI();
void stopTWI();

//Variables globales
volatile uint8_t twiStatus=0x00;

void initPorts(){
	//Configuro PIN del LED como salida (PB5 Arduino UNO)
	DDRB = (1 << DDB5);
	//PORTB |= (1<<PORTB5);
	//
	//Configuro PIN 2 digital como entrada digital
	DDRD &= ~(1<<DDD2);
	PORTD &=~ (1<<PORTD2);
	//
}



int main(void)
{
	cli();
	initPorts();
	sei();
	//while(!(PIND &(1<<PORTD2)));
	_delay_ms(1000);
    while (1) 
    {
			switch(twiStatus){
				case 0x00:
					startTWI();
					//PORTB |= (1<<PORTB5);
					break;
				
				case TWI_STARTED:
					sendSlaveAdress();
					//PORTB |= (1<<PORTB5);
					break;
				
				case SLA_W_SENT:
					dataToTWI();
					//PORTB |= (1<<PORTB5);	
					break;
				
				case DATA_SENT:
					stopTWI();
					twiStatus=0x01;
					//PORTB |= (1<<PORTB5);
					break;
			}	
    }
}

void startTWI(){
	//configuro SCLfreq = 100kHz
	TWBR=((F_CPU/SCL_CLOCK)-16)/2;		//Factor de division del bitrate generator = 32
	TWSR&=~(1<<TWPS0);//TWI Prescaler = 1
	TWSR&=~(1<<TWPS1);//TWI Prescaler = 1
	
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));//Espero a la bandera TWINT FLAG que indica q se genero el Start
	twiStatus=(TWSR & TWI_STARTED);
	PORTB |= (1<<PORTB5);
	
}

void sendSlaveAdress(){
	TWDR=0x78;
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG q indica q se transmitio la SLAVE_WRITE
	twiStatus=(TWSR & SLA_W_SENT);
	
	
}

void dataToTWI(){
	//control byte
	//TWDR=0b00000000;
	//TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	//while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG 

	TWDR=0xAE;//display OFF
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xD5;// Display clock divide ratio & Oscillator frequency
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	//
	PORTB |= (1<<PORTB5);
	//
	TWDR=0x80;//D5 default settings
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xA8;//Set Multiplex number(activated rows): ( range 16 ~ 64 )
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x3F;//Set Multiplex number(activated rows): ( N+1 )
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xD3;//Set display offset
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x00;//Set display offset ( range 0 ~ 63 )
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x40;//Set display RAM start line register
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x8D; //Charge pump: On=0x14, Off=0x10
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x14; //Charge pump: (Vcc supplied internally 0x14, Vcc supplied externally 0x10)
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xA1; //SEG (columns) normal(0xA0) mode, (inverse=0xA1)
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xC8; //COM (rows) normal mode(0xC0), (inverse=0xC8)
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xDA;//Set COM Pins Hardware config
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x12;//Set COM Pins Hardware config: Sequencial COM pin config & Disable COM Left/Right remap
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x81;//Set Contrast Control
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x9F;//Set Contrast Control
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
		//
	//TWDR=0x20;//Memory Addressing Mode 
	//TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	//while(!(TWSR & (1<<TWINT)));//Espero la TWINT FLAG
	//
	//TWDR=0x00;//Memory Addressing Mode (Horizontal=0 , Vertical=1 , Page=2)
	//TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	//while(!(TWSR & (1<<TWINT)));//Espero la TWINT FLAG
	//
	//TWDR=0x2E; //Disable Scroll
	//TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	//while(!(TWSR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xD9; //Pre-charge period 
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x22; //Pre-charge period 
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	
	TWDR=0xDB; //
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0x40; //
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xA5;// entire display ON
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xA7; //Display Normal mode, (inverse=0xA7)
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	TWDR=0xAF; //Display ON
	TWCR=((1<<TWINT)|(1<<TWEN));//Bajo la TWINT FLAG
	while(!(TWCR & (1<<TWINT)));//Espero la TWINT FLAG
	
	
	//PORTB |= (1<<PORTB5);
	
	twiStatus=(TWSR & DATA_SENT);
}

void stopTWI(){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
}
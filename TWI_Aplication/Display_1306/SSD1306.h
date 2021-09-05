/*
 * SSD1306.h
 *
 * Created: 5/9/2021 20:12:21
 *  Author: Nicolás
 */ 


#ifndef SSD1306_H_
#define SSD1306_H_

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
uint8_t disply1306InitTWI(uint8_t micro);
uint8_t disply1306SlaveAddrsTWI(uint8_t micro);
uint8_t disply1306Data(uint8_t micro,uint8_t data);
uint8_t disply1306StopTWI(uint8_t micro);
void disply1306Settings();
uint8_t disply1306DefaultInit();
uint8_t disply1306Write(uint8_t page,uint8_t cantLetras);
uint8_t cleanAllDisplay();
uint8_t cleanPage(uint8_t page);
void twiInterrupt();

//static uint8_t twi_Status=0;
//static uint8_t comando=0;
//const uint8_t texto[]={'H','O','L','A',' ','M','U','N','D','O'};
//






#endif /* SSD1306_H_ */
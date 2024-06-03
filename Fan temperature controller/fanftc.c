
/*******************
This program was created by the CodeWizardAVR V4.00a 
Automatic Program Generator
© Copyright 1998-2023 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 12/16/2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************/

#include<stdio.h>

// I/O Registers definitions
#include <mega32.h>

// Delay functions
#include <delay.h>


void delayMs(unsigned int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3180; j++)
            {
            
            }
    }
}

void delayUs(unsigned int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            
        }
    }
}
// Alphanumeric LCD functions
#include <alcd.h>

// ADC Voltage Reference: AREF pin
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))

int d;

// Read the AD conversion result
// Read Voltage=read_adc*(Vref/1024.0)
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}
       
void LCD_display_temperature_and_led(unsigned int temperature, unsigned char led_status)
{
    char buffer[30];
    lcd_clear();
    
    // Display temperature on the first row
    lcd_gotoxy(0, 0);
    sprintf(buffer, "Temperature=%i", temperature);
    
    lcd_puts(buffer);

    // Display LED status on the second row
    lcd_gotoxy(0, 1);
    if (led_status)
    {
        lcd_puts("Green LED/On");
    }
    else
    {
        lcd_puts("Red LED/On");
    }
}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=Out Bit0=Out 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=Out Bit0=Out 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);









// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);

// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Auto Trigger Source: Software
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0);
SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);



// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS: PORTD Bit 0
// RD: PORTD Bit 1
// EN: PORTD Bit 2
// D4: PORTD Bit 3
// D5: PORTD Bit 4
// D6: PORTD Bit 5
// D7: PORTD Bit 6
// Characters/line: 16
lcd_init(16);

while (1)
    {
        d = read_adc(0);
        d = d / 2;

        printf("ADC Value: %u\n", d); // Debug print

        if (d > 30)
        {
            printf("Green LED On\n"); // Debug print

            PORTB.0 = 1;
            delayMs(200);
            PORTB.0 = 0;
            delayMs(200);
            PORTC.0 = 0;
            PORTC.1 = 1;
            LCD_display_temperature_and_led(d, 1);
        }
        else
        {
            printf("Red LED On\n"); // Debug print

            PORTB.1 = 1;
            delayMs(200);
            PORTB.1 = 0;
            delayMs(200);
            PORTC.0 = 0;
            PORTC.1 = 0;
            LCD_display_temperature_and_led(d, 0);
        }
    }
}




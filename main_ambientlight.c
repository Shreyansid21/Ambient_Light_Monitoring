#include "header.h"

int main()
{
	u16 ret, op;
	spi0_init();
	uart1_init(9600);
	lcd_init();
	
	delay_ms(500);
	uart1_tx_string("SPI0 ADC\r\nLIGHT INTENSITY\r\n");
	while(1)
	{
		ret=mcp3204_adc_read(2);
		UART1_Tx_Integer(ret);
		uart1_tx_string("\r\n");
		op=(ret*100)/4095;
		UART1_Tx_Integer(op);
		uart1_tx_string("%\r\n\r\n");
	
		lcd_string("LIGHT INTENSITY");
		lcd_cmd(0xC0);
		
		lcd_integer(op);
		lcd_data(37);			//% symbol
		delay_s(1);
		lcd_cmd(0x01);
	}
}



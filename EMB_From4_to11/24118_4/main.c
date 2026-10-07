#include <LPC21xx.h>
#define LCD_DATA 0x000000FF
#define RS (1 << 16)
#define RW (1 << 17)
#define EN (1 << 18)
void delay(unsigned int count)
{
unsigned int i, j;
for(i = 0; i < count; i++)
for(j = 0; j < 6000; j++);
}
void lcd_enable(void)
{
IO1SET = EN;
delay(1);
IO1CLR = EN;
delay(1);
}
void lcd_command(unsigned char cmd)
{
IO1CLR = RS;
IO1CLR = RW;
IO0CLR = LCD_DATA;
IO0SET = cmd;
lcd_enable();
delay(2);
}
void lcd_data(unsigned char data)
{
IO1SET = RS;
IO1CLR = RW;
IO0CLR = LCD_DATA;
IO0SET = data;
lcd_enable();
delay(2);
}
void lcd_init(void)
{
delay(20);
lcd_command(0x38);
lcd_command(0x0C);
lcd_command(0x01);
lcd_command(0x06);
lcd_command(0x80);
}
void lcd_string(char *str)
{
while(*str)
{
lcd_data(*str);
str++;
}
}
int main(void)
{
PINSEL0 &= 0xFFFF0000;
PINSEL2 &= 0xFFFFFFC0;
IO0DIR |= LCD_DATA;
IO1DIR |= RS | RW | EN;
IO1CLR = RS | RW | EN;
lcd_init();
lcd_string("Ganath 24118");
lcd_command(0xC0);
lcd_string("LCD INTERFACING");
while(1);
}





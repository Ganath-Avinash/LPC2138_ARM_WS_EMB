#include <LPC21xx.H>
int main(void)
{
PINSEL0 = (1<<1); // Select PWM1 on P0.0
PWMPR = 0; // Prescaler
PWMMR0 = 1000; // Period
PWMMCR = (1<<1); // Reset PWMTC on PWMMR0 match
PWMLER = (1<<0); // Update PWMMR0
PWMPCR = (1<<9); // Enable PWM1 output
PWMTCR = (1<<1); // Reset PWM TC and PR
PWMTCR = (1<<0)|(1<<3); // Enable counter and PWM mode
PWMMR1 = 500; // 50% duty cycle
PWMLER = (1<<1); // Load MR1 value
while(1);
}
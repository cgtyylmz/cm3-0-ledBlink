#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

void init_gpio()
{
	// Setting rcc clock source
	rcc_clock_setup_in_hse_8mhz_out_48mhz();

	// Enable GPIOB clock Source
	rcc_periph_clock_enable(RCC_GPIOB);

	// Setting PA4 as output no pull  up no pull down
	gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);
}

int main()
{
	int i;

	// Gpio initialization
	init_gpio();

	while(1)
	{
		// Set GPIO HIGH
		gpio_set(GPIOB,GPIO4);

		for(i = 0; i<2000000; i++)
		{
			__asm__("nop");
		}

		// Set GPIO LOW
		gpio_clear(GPIOB, GPIO4);
		for(i = 0; i<2000000; i++)
		{
			__asm__("nop");
		}
	}
	return 0;
}

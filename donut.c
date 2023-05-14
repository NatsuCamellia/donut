// donut.c
#include <unistd.h>
#include "function.h"

int main()
{
	clear_screen();
	hide_cursor();

	for (;;)
	{
		reset_cursor();
		print_screen();
		usleep(30000);
	}
}
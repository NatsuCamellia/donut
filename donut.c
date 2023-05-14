// donut.c
#include <unistd.h>
#include "donut.h"
#include "function.h"

int main()
{
	float A = 0;
	float B = 0;
	clear_screen();
	hide_cursor();

	for (;;)
	{
		reset_cursor();
		print_screen(A, B);

		A += omega_A;
		B += omega_B;
		usleep(30000);
	}
}
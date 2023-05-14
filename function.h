// function.h
#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <math.h>
#include <string.h>

void clear_screen()
{
	printf("\x1b[2J");
}

void print_screen()
{
	printf("print_screen\n");
}

void hide_cursor()
{
	printf("\033[?25l");
}

void reset_cursor()
{
	printf("\x1b[H");
}

#endif

#ifndef FUNCTION_H
#define FUNCTION_H
 
#include <stdio.h>
#include <math.h>
#include <string.h>
 
void clear_screen() {
    printf("\x1b[2J");
}
 
void print_screen(float A, float B) {
    printf("print_screen %f %f\n", A, B);
}
 
void hide_cursor() {
    printf("\033[?25l") ;
}
 
void reset_cursor() {
    printf("\x1b[H");
}
 
coordinate get_projection(float theta, float phi, float A, float B) {
    return (coordinate){ .x=0, .y=0, .z=0 };
}
 
float get_luminance(float theta, float phi, float A, float B) {
    return 0;
}
 
void get_output(float L, coordinate pos) {
}
 
#endif
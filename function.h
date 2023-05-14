// function.h
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
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++)
            putchar(output[j][i]);
        putchar('\n');
    }
}

void hide_cursor() {
    printf("\033[?25l") ;
}

void reset_cursor() {
    printf("\x1b[H");
}

void reset_values() {
    memset(output, (int)' ', sizeof(output)) ;
    memset(bestOOZ, 0, sizeof(bestOOZ)) ;
}

coordinate get_projection(float theta, float phi, float A, float B) {
    return (coordinate){ .x=0, .y=0, .z=0 };
}

float get_luminance(float theta, float phi, float A, float B) {
    return 0;
}

void get_output(float L, coordinate pos) {
    // larger ooz means closer to viewer, reset output for closer z
    float ooz = 1 / pos.z ; // one over z
    if(ooz > bestOOZ[pos.y][pos.x]) {
        bestOOZ[pos.y][pos.x] = ooz ;
        output[pos.y][pos.x] = L > 5 ? '@' : '.';
    }
}

#endif

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
    float costheta = cos(theta), sintheta = sin(theta);
    float cosphi = cos(phi), sinphi = sin(phi);
    float cosA = cos(A), sinA = sin(A) ;
    float cosB = cos(B), sinB = sin(B) ;
 
    // the x,y coordinate of the circle before revolving
    float circlex = R2 + R1*costheta;
    float circley = R1*sintheta;
 
    // final 3D (x,y,z) coordinate after rotations 
    coordinate pos ;
    float x = circlex*(cosB*cosphi + sinA*sinB*sinphi) - circley*cosA*sinB ; 
    float y = circlex*(sinB*cosphi - sinA*cosB*sinphi) + circley*cosA*cosB ;
    float z = donut_distance + cosA*circlex*sinphi + circley*sinA ;
 
    // (x,y,z) after projection
    pos.x = (int) (width/2 + render_distance*x/z);
    pos.y = (int) (height/2 - render_distance*y/z);
    pos.z = z ;
 
    return pos ;
}
 
float get_luminance(float theta, float phi, float A, float B) {
    // calculate luminance, range from -sqrt(2) to +sqrt(2). 
    return cos(phi)*cos(theta)*sin(B) - cos(A)*cos(theta)*sin(phi) - sin(A)*sin(theta) + cos(B)*(cos(A)*sin(theta) - cos(theta)*sin(A)*sin(phi));
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
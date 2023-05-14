#ifndef DONUT_H
#define DONUT_H
 
#define width 30
#define height 30
 
const float pi = 3.1415926 ;
const float dtheta = 0.07 ;
const float dphi   = 0.02 ;
 
const float omega_A = 0.07;
const float omega_B = 0.04;
 
const float R1 = 1 ;
const float R2 = 2 ;
const float donut_distance = 5 ;
const float render_distance = width*donut_distance*3/(8*(R1+R2));
 
const char pattern[] = ".,-~:;=!*#$@" ;
 
typedef struct Tcoordinate {
    int x ;
    int y ; 
    float z ;
} coordinate ;
 
char output[height][width] ;
float bestOOZ[height][width] ;
 
#endif
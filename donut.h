// donut.h
#ifndef DONUT_H
#define DONUT_H

#define width 30
#define height 30

const float pi = 3.1415926 ;
const float dtheta = 0.07 ;
const float dphi   = 0.02 ;

const float omega_A = 0.07;
const float omega_B = 0.04;

typedef struct Tcoordinate {
    int x ;
    int y ; 
    float z ;
} coordinate ;

char output[height][width] ;
float bestOOZ[height][width] ;

#endif
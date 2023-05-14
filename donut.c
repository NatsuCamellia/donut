// donut.c
#include <unistd.h>
#include "donut.h"
#include "function.h"

int main() {
    float A = 0 ;
    float B = 0 ;
    clear_screen() ;
    hide_cursor() ;

    for(;;) {
        reset_values() ;
        for (float theta=0; theta < 2*pi; theta += dtheta) {
            for(float phi=0; phi < 2*pi; phi += dphi) {
                coordinate pos = get_projection(theta, phi, A, B) ;
                float L = get_luminance(theta, phi, A, B) ;
                get_output(L, pos) ;
            }
        }
        reset_cursor() ;
        print_screen(A, B) ;

        A += omega_A ;
        B += omega_B ;
        usleep(30000) ;
    }
}
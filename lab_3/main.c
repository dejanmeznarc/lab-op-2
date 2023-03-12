#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "stdbool.h"


#define ACCURACY 0.00001


complex guessSqrtCloser(complex number, complex guess, double pwr);


int main() {

    complex number = 5 + 4 * I;
    complex guess = 4;

    guess = guessSqrtCloser(number, 10, 3);


    printf("Complex: %f %f\n", creal(guess), cimag(guess));
    return 0;
}


complex guessSqrtCloser(complex number, complex guess, double pwr) {
    guess = guess - (pow(guess, pwr) - number) / (pwr * guess);


    if (fabsf(guess - sqrtf(number)) > ACCURACY) {
        return guessSqrtCloser(number, guess, pwr);
    }
    return guess;
}

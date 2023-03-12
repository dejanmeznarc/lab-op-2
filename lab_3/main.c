#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "stdbool.h"

#define ACCURACY 0.000001

complex double guessThirdRootCloser(complex double number, complex double guess);


int main() {


    complex double solution = guessThirdRootCloser(1, 0.8 * I);

    printf("Complex: Re= %f Im= %f\n", creal(solution), cimag(solution));
    return 0;
}


complex double guessThirdRootCloser(complex double number, complex double guess) {
    guess = guess - (guess * guess * guess - number) / (3 * guess * guess);


    if (cabs(guess - sqrt(number)) > ACCURACY) {
        return guessThirdRootCloser(number, guess);
    }
    return guess;
}
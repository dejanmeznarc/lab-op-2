#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "stdbool.h"

#define ACCURACY 0.0001

complex double guessSqrtCloser(complex double number, complex double guess);


int main() {


    complex double solution = guessSqrtCloser(1, 2);

    printf("Complex: %z\n", solution);
    return 0;
}


complex double guessSqrtCloser(complex double number, complex double guess) {
    guess = guess - (guess * guess - number) / (2 * guess);


    if (cabs(guess - sqrt(number)) > ACCURACY) {
        return guessSqrtCloser(number, guess);
    }
    return guess;
}
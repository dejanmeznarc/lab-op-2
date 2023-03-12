#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "stdbool.h"

#define ACCURACY 0.000001

complex double guessThirdRootCloser(complex double number, complex double guess);

void printComplex(complex double num);

int isInRangeComplex(complex double guess, complex double solution) {

    complex double delata = cabs(guess - solution);

    return (creal(delata) < ACCURACY) &&
           (cimag(delata) < ACCURACY);

}

#define SOLUTIONS_NUM 3
const complex double solutions[SOLUTIONS_NUM] = {
        1,
        -0.5 + 0.866025404 * I, // -0.5 + I*sqrt(3)/2
        -0.5 - 0.866025404 * I, // -0.5 + I*sqrt(3)/2
};


int main() {


    complex double solution = guessThirdRootCloser(1, -1+4*I);

    printComplex(solution);

    return 0;
}


complex double guessThirdRootCloser(complex double number, complex double guess) {

    guess = guess - (guess * guess * guess - number) / (3 * guess * guess);

    for (int i = 0; i < SOLUTIONS_NUM; ++i) {
        if (isInRangeComplex(guess, solutions[i])) {
            return guess;
        }
    }

    return guessThirdRootCloser(number, guess);
}

void printComplex(complex double num) {
    printf("Complex: Re= %f Im= %f\n", creal(num), cimag(num));
}




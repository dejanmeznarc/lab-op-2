#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "stdbool.h"
#include "libs/bitmap/bitmap.h"

#define ACCURACY 0.000001

#define SOLUTIONS_NUM 3
//const complex double number = 1;
//const complex double solutions[SOLUTIONS_NUM] = { // 3rd root of 1
//        1,
//        -0.5 + 0.866025404 * I, // -0.5 + I*sqrt(3)/2
//        -0.5 - 0.866025404 * I, // -0.5 - I*sqrt(3)/2
//};

const complex double number = 5;
const complex double solutions[SOLUTIONS_NUM] = { // 3rd root of 5
        1.70997595,
        -0.854987974 + 1.48088261 * I,
        -0.854987974 - 1.48088261 * I,
};


complex double guessNthRootCloser(unsigned int root, complex double num, complex double guess, unsigned int *guess_num);

void printComplex(complex double num);

int isInRangeComplex(complex double guess, complex double solution);

int getSolutionIndex(complex double solution) {
    for (int i = 0; i < SOLUTIONS_NUM; ++i) {
        if (isInRangeComplex(solution, solutions[i])) {
            return i;
        }
    }
}


unsigned int bitmap[1000][1000] = {0};


int main() {

    // test funcs
//    complex double solution = guessNthRootCloser(3, 1, -1 + 4 * I);
//    printComplex(solution);

//    // what if guess=0+0i?'?
//    complex double dehjan = guessNthRootCloser(3, 1, 0);
//    printComplex(dehjan);



    // scroll through all from -500...499 for im and re
    for (int re = -500; re < 499; ++re) {
        for (int im = -500; im < 499; ++im) {
            if (!re && !im) continue; //ignore zeros

            const complex double firstGuess = re + im * I;
            unsigned int number_of_guesses = 1;
            const complex double sol = guessNthRootCloser(3, number, firstGuess, &number_of_guesses);


            if(number_of_guesses > 50){
                continue;
            }

            switch (getSolutionIndex(sol)) {
                case 0:
                    bitmap[re + 500][im + 500] = 80 + number_of_guesses;//80
                    break;
                case 1:
                    bitmap[re + 500][im + 500] = 160 + number_of_guesses;//160
                    break;
                case 2:
                    bitmap[re + 500][im + 500] = 240 + number_of_guesses;//240
                    break;
            }
//
//            printComplex(number);
//            printf("\t");
//            printComplex(sol);
//            printf("\n");

        }
    }

    const int fnd_x = 700; //700
    const int fnd = 775; //775

    for (int i = fnd_x; i < fnd_x + 75; ++i) {
        for (int j = fnd; j < fnd + 75; ++j) {
            printf("%d\t", bitmap[i][j]);
        }
        printf("\n");
    }

    shraniBMP(bitmap, 1000, 1000, "dejan_7.bmp");

    return 0;
}


complex double guessNthRootCloser(unsigned int root, complex double num, complex double guess, unsigned int *guess_num) {

    guess = guess - (cpow(guess, root) - num) / (root * cpow(guess, root - 1));

    for (int i = 0; i < root; ++i) {
        if (isInRangeComplex(guess, solutions[i])) {
            return guess;
        }
    }

    (*guess_num)++;

    return guessNthRootCloser(root, num, guess, guess_num);
}

void printComplex(complex double num) {
    printf(" Re= %f Im= %f ", creal(num), cimag(num));
}

int isInRangeComplex(complex double guess, complex double solution) {

    complex double delata = cabs(guess - solution);

    return (creal(delata) < ACCURACY) &&
           (cimag(delata) < ACCURACY);

}




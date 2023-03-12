#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include "math.h"

#define ACCURACY 0.00001


float guessSqrtCloser(float number, float guess);


int main() {
    printf("Sqrt of 2= %f (expected %f)\n\n", guessSqrtCloser(2,84), sqrtf(2));

    int x = 4;
    int y = 3;
    x=20 || y++ ;
    printf("%d",x);

    printf("Trying for all: \ncalcluated\treal\n");
    for (int i = 0; i < 30; ++i) {

        float clac = guessSqrtCloser((float)i,2);

        printf("%f\t%f\n", clac, sqrt(i));
    }


    return 0;
}




float guessSqrtCloser(float number, float guess) {
    guess = guess - (guess * guess - number) / (2 * guess);


    if(fabsf(guess - sqrtf(number)) > ACCURACY){
        return guessSqrtCloser(number, guess);
    }
    return guess;
}
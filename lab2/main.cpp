#include <iostream>
#include <cmath>

float solveSqRt(float);

int main() {
    float dejan = solveSqRt(2);

    printf("sqet2 %f",dejan);

    return 0;
}



// bolj učinkovita zadeva
float solveSqRt(float num){
    return num - sqrt(num)/ (1/(2*num));
}



// zelo učinkovita metoda
float solveSqRoot(float num){
    // get closest sq number


    // calculate sqrt of that number
    // calc h
    // clac dirivative
    // do math



}


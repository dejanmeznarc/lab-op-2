#include <stdio.h>

int main() {
    int monthDays = 76, monthFirstDay = 5;

//    printf("Št dni v mesecu:\n");
//    scanf("%d", &monthDays);
//
//    printf("Prvi dan (1-pon,7ned):\n");
//    scanf("%d", &monthFirstDay);

    printf("P\t T\t S\t Č\t P\t S\t N\n");

    unsigned int dayNumber=1;

    for (int i = 1; i < (monthFirstDay+monthDays); ++i) {

        if(i < monthFirstDay){
            printf("\t");
        }else{
            printf("%d\t", dayNumber++);
        }


        printf(" ");
        if(i % 7 == 0) printf("\n");
    }

    return 0;
}

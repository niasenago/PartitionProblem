#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "function.h"

#define CAPACITY 100

int main(int argc, char *argv[]){
    int nums[CAPACITY];
    int subset1[CAPACITY], subset2[CAPACITY];
    int n;
    int subset1lenght = 0, subset2lenght = 0;

    if(argc == 1){      //no arguments are supplied
        printf("Please, next time enter filename.\n");
        return -1;
    }

    int sum = getData(argv[1], nums, &n);
    int targetValue = sum / 2; 

    displayArray(nums, n);
    printf("sum is %d target is : %d\n", sum, targetValue);
    
    devideSubset(nums, n, targetValue, subset1,subset2, &subset1lenght, &subset2lenght);

    printf("subsets with minimum sum difference are: \n");
    displayArray(subset1, subset1lenght);
    displayArray(subset2, subset2lenght);

    return 0;
}
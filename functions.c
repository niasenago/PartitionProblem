#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "function.h"
#define CAPACITY 100

//function reads integers untill the end of file
//function as a side effect returns weight sum and n of elements
//filename: filename with input data
//numArray: array to store integers
//n: number of integers
int getData(char fileName [], int numArray[], int *n){ 
    FILE *inputFile = fopen(fileName, "r");

    if(inputFile == NULL){
        printf("File not found\n");
        exit(EXIT_FAILURE);
    }
    int weightSum = 0;
    int i = 0;
    while(fscanf(inputFile, "%d", &numArray[i]) == 1){
        weightSum +=numArray[i];
        ++i;
    }
    *n = i;
    if(*n > CAPACITY){
        printf("In %s too many numbers", fileName);
    }      
     
    fclose(inputFile);
    return weightSum;
}

//function prints to the stdout integers from the array
//array: array with integers
//n: number of integers
void displayArray(int array[], int n){
    for(int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}


int minDifference = INT_MAX;
int bestSubset[CAPACITY];   // the most suitable subset at the moment
int bestSubsetLenght;

// arr: input array
// i: index of input array
// n: size of arr
// subset: array to store the subset
// j: current size of subset
// target: target sum of subset;
//function finds all possible subsets
void checkAllSubsets(int arr[], int i, int n,int subset[], int j, int target){    
    if(i == n){
        int idx = 0;
        int sum = 0;
        int difference = 0;
        while(idx < j){
            sum +=subset[idx];
            ++idx;
        }
        
        difference = abs(target - sum);
        if(difference < minDifference){
            minDifference = difference;
            for(int i = 0; i < idx; ++i)
                bestSubset[i] = subset[i];
            bestSubsetLenght = idx;
        }
        return;
    }
    
    // case 1: i is not included in the subset
    checkAllSubsets(arr, i + 1, n, subset, j,target);

    // case 2: i is included in the subset
    subset[j] = arr[i];
    checkAllSubsets(arr, i + 1, n, subset, j + 1, target);
}

void devideSubset(int arr[], int n, int target, int subset1[], int subset2[], int *subset1size, int *subset2size){
    
    bool isInSubset1[n];
    int tempSubset[CAPACITY];
    checkAllSubsets(arr, 0, n, tempSubset, 0, target);
    for(int i = 0; i < n ; ++i)
        isInSubset1[i] = 0;

    for(int i = 0; i < bestSubsetLenght; ++i){
        for(int j = 0; j < n; ++j){
            if((isInSubset1[j] == false) && (arr[j] == bestSubset[i]) ){ // &&(isInSubset1[j] == false)
                isInSubset1[j] = true;
                break;
            } 
        }
    }        
    
    for(int i = 0; i < n; ++i){
        if(isInSubset1[i]){
            subset1[(*subset1size)] = arr[i];
            ++(*subset1size);
        }else{
            subset2[(*subset2size)] = arr[i];
            ++(*subset2size);
        }
    }
}
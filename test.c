
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define CAPACITY 100

//function reads integers untill the end of file
int getData(char fileName [], int numArray[], int *n){ // side effect returns weight sum and n of elements
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
    // check if where was more numbers than capacity of array !!  
    
    fclose(inputFile);
    return weightSum;
}


    
void displayArray(int array[], int n){
    for(int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}


int minDifference = INT_MAX;
int bestSubset[CAPACITY];
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
    // in this case simply increment i and move ahead
    checkAllSubsets(arr, i + 1, n, subset, j,target);
    // case 2: i is included in the subset
    // insert arr[i] at the end of subset
    // increment i and j
    subset[j] = arr[i];
    checkAllSubsets(arr, i + 1, n, subset, j + 1, target);
        
}

void devideSubset(int arr[], int n, int target, int subset1[], int subset2[], int *subset1size, int *subset2size){
    bool isInSubset1[n];
    int tempSubset[CAPACITY];
    checkAllSubsets(arr, 0, n, tempSubset, 0, target);
    for(int i = 0; i < n ; ++i){
        isInSubset1[i] = false;
    
        for(int i = 0; i < bestSubsetLenght; ++i){
            for(int j = 0; j < n; ++j){
                if(arr[j] == bestSubset[i])
                    isInSubset1[j] = true;
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

int main(){
    int nums[CAPACITY];
    int subset1[CAPACITY], subset2[CAPACITY];
    int n;
    int subset1lenght = 0, subset2lenght = 0;


    int sum = getData("input.txt", nums, &n);
    int targetValue = sum / 2; 

    displayArray(nums, n);
    printf("sum is %d target is : %d\n", sum, targetValue);
    
    devideSubset(nums, n, targetValue, subset1,subset2, &subset1lenght, &subset2lenght);

    printf("subsets with minimum sum difference are: \n");
    displayArray(subset1, subset1lenght);
    displayArray(subset2, subset2lenght);

    return 0;
}
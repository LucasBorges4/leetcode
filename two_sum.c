#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 1000

int* twoSum(int* nums, int numsSize, int target, int* returnSize){  
    int* solution = (int*) calloc(2, sizeof(int));

    *returnSize = 0;

    if (solution == NULL){
        return returnSize;
    }
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target && i != j) {
                *returnSize = 2;
                solution[0] = i;
                solution[1] = j;
                return solution;
            }
        }
    }

    return solution;
}

int main(){
    unsigned nums[MAX_TAM] = {2, 7, 11, 15};
    unsigned target = 9;
    


    return 0;
}
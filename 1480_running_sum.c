/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize){
    int* vector = (int*) malloc(numsSize*sizeof(int));
    vector[0] = nums[0];
    *returnSize = numsSize;
    for (int i = 1 ; i < numsSize; i++) {
        vector[i] = nums[i] + vector[i - 1];
    }
    return vector;
}


int main(){




    return 0;
}
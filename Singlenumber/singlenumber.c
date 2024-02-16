#include <stdio.h>
#define length 3

int singleNumber(int* nums, int numsSize) {
    int resultado = 0;
    for (size_t i = 0; i < numsSize; i++){
        resultado ^= nums[i];
    }
    return resultado;
}  // Best Time: 7ms 6.86Mb

int singleNumberRecursive(int* nums, int numSize) {
    
    if (numSize == 1) {
        return nums[0];
    }
    
    int middle, leftUnique, rightUnique;

    middle = numSize / 2;
    leftUnique = singleNumberRecursive(nums, middle);
    rightUnique = singleNumberRecursive(nums + middle, numSize - middle);

    return leftUnique ^ rightUnique;
}

int singleNumberRecursive2(int* nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int middle = (left + right) / 2;
    int leftUnique = singleNumberRecursive2(nums, left, middle);
    int rightUnique = singleNumberRecursive2(nums, middle + 1, right);

    return leftUnique ^ rightUnique;
}

int main(void){
    int array[length] = {2, 2, 1};
    int single = singleNumber(array, length);
    printf(single);

    return 0;
}

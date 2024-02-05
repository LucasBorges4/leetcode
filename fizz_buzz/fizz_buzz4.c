#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fizzBuzzHelper(int num) {
    char* result;

    if (num % 3 == 0 && num % 5 == 0) {
        result = strdup("FizzBuzz");
    } else if (num % 3 == 0) {
        result = strdup("Fizz");
    } else if (num % 5 == 0) {
        result = strdup("Buzz");
    } else {
        char temp[12];
        sprintf(temp, "%d", num);
        result = strdup(temp);
    }

    return result;
}

void fizzBuzzRecursion(int n, char** answer, int index) {
    if (n < 1) {
        return;
    }

    fizzBuzzRecursion(n - 1, answer, index);

    answer[index + n - 1] = fizzBuzzHelper(n);
}

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** answer = (char**)malloc(sizeof(char*) * n);

    fizzBuzzRecursion(n, answer, 0);

    return answer;
}

int main(void) {
    int length;
    char** answer;

    printf("Digite o valor de n: ");
    scanf("%d", &length);

    int returnSize;
    answer = fizzBuzz(length, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        if (i == returnSize - 1) {
            printf("\"%s\"", answer[i]);
        }
        else {
            printf("\"%s\",", answer[i]);
            free(answer[i]);
        }
    }
    printf("]\n");

    free(answer);

    return 0;
}

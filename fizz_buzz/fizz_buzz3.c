#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

char** fizzBuzz(int n, int* returnSize) {
    char** answer = (char**)malloc(sizeof(char*) * n);
    *returnSize = n;

    #pragma omp parallel for 
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
            answer[i] = strdup("FizzBuzz");
        } else if ((i + 1) % 3 == 0) {
            answer[i] = strdup("Fizz");
        } else if ((i + 1) % 5 == 0) {
            answer[i] = strdup("Buzz");
        } else {
            char temp[12]; // Suficientemente grande para armazenar qualquer número de 32 bits
            sprintf(temp, "%d", i + 1);
            answer[i] = strdup(temp);
        }
    }

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

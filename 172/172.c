#include <stdio.h>

int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}

//Algoritmo de arquimedes
int trailingZeroes2(int n) {
    int count = 0;
    
    // Itera enquanto n for maior que 0
    while (n > 0) {
        // Divide n por 5 e adiciona o resultado ao contador
        count += n / 5;
        // Atualiza n para o próximo valor em que 5 é um fator
        n /= 5;
    }
    
    return count;
}

int main(void){
    int n = 10;
    int result = trailingZeroes(n);
    printf("%d\n", result);

    return 0;
}
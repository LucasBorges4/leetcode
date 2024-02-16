#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define INT_MIN -2147483648
#define INT_MAX 2147483647


int reverse(int x){
    long rev = 0; // Usando um tipo long para evitar estouro de inteiro
    while (x != 0){ // Enquanto x for diferente de zero
        int lastDigit = x % 10; // Obtém o último dígito de x
        rev = rev * 10 + lastDigit; // Adiciona o último dígito a rev
        x /= 10; // Remove o último dígito de x
    }
    // Verifica se x era negativo antes da inversão
    // Se for, inverte o sinal de rev
    return (rev < INT_MIN || rev > INT_MAX) ? 0 : rev;
}

int main(void){
    printf("%d\n", reverse(120));

    return 0;
}
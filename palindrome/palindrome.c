#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    
    // Se o número for negativo ou terminar com zero (exceto zero), não será um palíndromo.
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int reversed = 0;

    // Inverte o número pela metade.
    while (x > reversed) {
        int lastDigit = x % 10;
        reversed = reversed * 10 + lastDigit;
        x /= 10;
    }

    // Se o número de dígitos for par, x e reversed devem ser iguais.
    // Se for ímpar, podemos ignorar o dígito do meio.
    return x == reversed || x == reversed / 10;
}

int main(void){
    // Teste da função isPalindrome
    int num = 12321;
    if (isPalindrome(num)) {
        printf("%d é um palíndromo.\n", num);
    } else {
        printf("%d não é um palíndromo.\n", num);
    }
    return 0;
}
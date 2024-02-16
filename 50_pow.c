#include <stdio.h>
#include <math.h> // Para a função fabs

#define DOUBLE_MIN -1.0e308
#define DOUBLE_MAX 1.0e308

#define INT_MIN -2147483648
#define INT_MAX 2147483647

double myPow(double x, long n) {
    if (x < DOUBLE_MIN || x > DOUBLE_MAX || n < INT_MIN || n > INT_MAX)
        return -1.0; // Retornar um valor inválido se x ou n estiverem fora dos limites
    
    if (x == 0 && n < 0)
        return INFINITY; // Retornar infinito se x for zero e n for negativo
    
    if (n == 0)
        return 1.0; // Qualquer número elevado a 0 é 1
    
    double result = 1.0;
    long long power = n; // Usar long long para evitar estouro de inteiros
    
    if (power < 0) {
        x = 1.0 / x;
        power = -power;
    }

    while (power > 0) {
        if (power & 1) {
            result *= x;
        }
        
        x *= x;
        power >>= 1;
    }

    return result;
}

int main(void){
    printf("%f\n", myPow(2.0, -1));
    return 0;
}

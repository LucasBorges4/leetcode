#include <stdio.h>

typedef union type_u {
    int i; 
    float f;
} type_u;

typedef enum type_t {
    INT,
    FLOAT
} type_t;
    
typedef struct array_s {
    type_t tag; type_u data[100];
} double_array;

int main(void){
    double_array a;
    for (size_t i = 0; i < 50; i++){
        a.data[i].i = i;
    }
    
    for (size_t i = 0; i < 50; i++){
        a.data[i].i = i/7;
    }
    
    printf("%d\n", a.data[0].i);
    printf("%f\n", a.data[51].f);

	return 0;
}
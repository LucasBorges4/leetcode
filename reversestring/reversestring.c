#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    char temp;
    int left = 0;
    int right = sSize - 1;
    while(left < right){
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main(void){
    char s[5] = "hello";
    reverseString(s, strlen(s));
    printf("%s\n", s);

    return 0;
}
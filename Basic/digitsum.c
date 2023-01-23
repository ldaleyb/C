#include <stdio.h>

int main () {

int num;
int sum = 0;
scanf("%d", &num);

while (num != 0) {
    sum+= num % 10;
    num/=10;
    }

printf("The digit sum is %d", sum);

    return 0;
}
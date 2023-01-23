/*Lauren Brackin CS100 Lab2-3
Program that takes user input in the form of an integer (n) and prints 
an upside down triangle with each row starting at n number of points 
with the next row containing n-1 points and so on until n=1
*/

#include <stdio.h>

int main () {

int n;
scanf("%d", &n);

for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        printf(" ");
    }
    for (int k = i; k < n; k++) {
        printf("* ");
    }
    printf("\n");
}

    return 0;
}
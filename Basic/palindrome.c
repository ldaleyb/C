/*
Takes user input string and determines if it is a palindrome
Example input : tacocat
        output: is a palindrome
Example input : taco 
        output: is not a palindrome

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main () {
char str[100];
int n, i;
int check = 1;
fgets(str, 100, stdin);
n = strlen(str) -1;

for (int j = 0; j <= n; j++) {
    if (str[j] == ' ') {
        for(int k = j; k <= n; k++) {
				str[k]=str[k+1];
			}
		n--;
    }
}
for (i = 0; i < n / 2; i++) {
    if (tolower(str[i]) != tolower(str[n-i-1])) {
        check = 0; 
        break;
    }
}
if (check == 0) {
    printf("%s is not a palindrome.", str);
}
else if (check == 1) {
    printf("%s is a palindrome.", str);
}
    return 0;
}

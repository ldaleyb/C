/*
This lab converts a hex number scanned in string format) to decimal format.
User won't be prompted so after ./a (enter) just enter the hex number.
User can enter up to an 8 digit hex number to be converted.
User must enter all letters in uppercase format
To check: The hex number 10 is equal to 16 in base 10
          The hex number 10000000 is equal to 268435456 in base 10
          The hex number F is equal to 15 in base 10
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {

char str[9];
scanf("%s", str);
int n;
int dec = 0;
int pow = 1;
n = strlen(str);
for (int i = n; i >= 0; i--) {
    if ((str[i] >= '0') && (str[i] <= '9')) {
        dec+= (str[i] - 48) * pow;
        pow*=16;
    }
    else if ((str[i] >= 'A') && (str[i] <= 'F')) {
        dec+= (str[i] -55) * pow;
        pow*=16;
    }
    
}
printf("The hex number is equal to %d in base 10.", dec);

    return 0;
}

/*Returns number of uppercase chars, lowercase chars,
and digits in user-entered cmd line arg. This program
only takes two cmd line arguments; ./a.out and <argv[1]>.
This was implemented in two ways. Uncomment the part below, 
and the results should be the same.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char **argv) {
    int len = strlen(*(argv+1));
    int upper = 0;
    int lower = 0;
    int digits = 0;
    for (int i = 0; i < len; i++) {
        if (isupper( *(*(argv + 1) + i)) ) {
                upper++;
            }
            else if (islower( *(*(argv + 1) + i)) ) {
                lower++;
            }
            else if (isdigit( *(*(argv + 1) + i)) ) {
                digits++;
            }
    }
    printf("Uppers = %d\n", upper);
    printf("Lowers = %d\n", lower);
    printf("Digits = %d", digits);


    return 0;
}

/*
int main (int argc, char *argv[]) { 
    int len = strlen(argv[1]);
    int upper = 0;
    int lower = 0;
    int digits = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(argv[1][i])) {
                upper++;
            }
            else if (islower(argv[1][i])) {
                lower++;
            }
            else if (isdigit(argv[1][i])) {
                digits++;
            }
    }
    printf("Uppers = %d\n", upper);
    printf("Lowers = %d\n", lower);
    printf("Digits = %d", digits);


    return 0;
}*/
/*Returns total number of uppercase chars, lowercase chars,
and digits from data.txt file. To run: ./a data.txt */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    char str[50];
    while (!feof(fp)) {
        while (fscanf(fp, "%s", str) != '\n') {
        int len = strlen(str);
        int upper = 0;
        int lower = 0;
        int digits = 0;
        for (int i = 0; i < len; i++) {
            if (isupper(str[i])) {
                upper++;
            }
            else if (islower(str[i])) {
                lower++;
            }
            else if (isdigit(str[i])) {
                digits++;
            }
        }
        printf("%s -%d uppercase, %d lowercase, %d digits\n", str, upper, lower, digits);
        if (feof(fp)) {
            break;
        }
      }
    }

    return 0;
}
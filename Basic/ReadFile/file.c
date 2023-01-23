/*This program reads in input .txt file provided by the 
user and prints the contents of the file. To run: ./a file.txt */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
FILE *fp = fopen(argv[1], "r");

if(!fp) {
    printf("Error opening %s\n", argv[1]);
    return 1;
}

while (!feof(fp)) {
    char ch;
    ch = fgetc(fp);
    char *str1[10], *str2[10];
    fscanf(fp, "%s\n\n%s\n\n", str1, str2);
    printf("Set %c contains '%s' and '%s'\n", ch, str1, str2);   
}
    return 0;
}
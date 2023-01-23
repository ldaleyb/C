/*This program functions as a basic word processor that prompts user
for string input, column width, alignment, and an option to autocorrect, and 
returns the user entered string with the selected format adjustments. 
Example inputs can be found in the .txt files */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main () {

printf("Input: ");
char str[1000];
int wordcount = 0;
int length = 0;
int size = 0;
scanf("%[^\n]s", str);
    for (int i = 0; str[i] != '\0'; i++) {

         if ((str[i] == ' ') && (str[i+1] != ' ')) { //probably dont need that
            wordcount++; 
        }          
        else if ((!ispunct(str[i]) && (!isdigit(str[i])))) {
            length++;
        }
            size++;       
    }//final is count +1

printf("\nColumn width: ");
int width;
scanf("%d", &width);

if (width < size) {
    printf("Invalid column width\n");
    return 0;
}

printf("\nAlignment: ");
char align[10];
scanf("%s", align);

printf("\nAutocorrect: ");
char ans[4];
scanf("%s", ans);

if (strcmp(ans, "yes") == 0) {
    for (int i = 0; str[i] != '\0'; i++) {
        
        if (str[i] == '3') {
            str[i] = 'e';
            length++;
        }
        if (str[i] == '1') {
            str[i] = 'l';
            length++;
        }
        if (str[i] == '0') {
            str[i] = 'o';
            length++;
        }
        if (str[i] == '7') {
            str[i] = 't';
            length++;
         
        }
        if ((str[i] == '.') && (str[i+1] == ' ')) {
            str[i+2] = toupper(str[i+2]);
        }
        if (i == 0) {
            str[i] = toupper(str[i]);
        }
        if (((isalpha(str[i]) || isdigit(str[i]))) && str[i+1] == '\0') {
            strcat(str, ".");
            width++;
            size++;
        }
    }    
}

for (int i = 0; i < width; i++) {
    printf("-");
}

printf("\n");

if (strcmp(align, "left") == 0) {
    printf("%s", str);
}

else if (strcmp(align, "right") == 0) {
    int numspaces = width - size;
    for (int i = 0; i < numspaces; i++) {
        printf(" ");
    }
    printf("%s", str);
}

else if (strcmp(align, "center") == 0) {
    int center = (width - size + 1) / 2;
    //printf("'%s'-\n", str);
    // if ((width % 2 != 0) && (size % 2 == 0)) {// wordcount or size
    //     center++;
    // }
    // else if ((width % 2 == 0) && (size % 2 != 0)) {
    //     center++;
    // }
    //printf("center: %d\nwidth: %d\nsize: %d\n", center, width, size);
    for (int i = 0; i < center; i++) {
        printf(" ");
    }
    printf("%s", str);
}

printf("\nWords: %d", wordcount+1);

length = 0;
for (int i = 0; str[i] != '\0'; i++) {
    if (isalpha(str[i])) {
        length++;
    }
}
printf("\nAvg word length: %lf\n", (double)length/(wordcount+1));

    return 0;
}
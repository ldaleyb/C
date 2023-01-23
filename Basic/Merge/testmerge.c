#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

     // Open two files to be merged
     FILE *fp1 = fopen("file1.txt", "r");
     FILE *fp2 = fopen("file2.txt", "r");
     FILE *fp3 = fopen("test3.txt", "w");

     if (fp1 == NULL || fp2 == NULL)
     {
           printf("Could not open files");
     }
     printf("Merged file1.txt and file2.txt: ");
     int a;
     int b;
     fscanf(fp1, "%d", &a);
     fscanf(fp2, "%d", &b);
    while (1) {
        if (feof(fp1) && feof(fp2)) {
            break;
        }
            if (a <= b) {
                fprintf(fp3, "%d", a);
                printf("%d ", a);
                fscanf(fp1, "%d", &a);
            }
            if (b < a) {
                fprintf(fp3, "%d", b);
                printf("%d ", b);
                fscanf(fp2, "%d", &b);
            }
            if (feof(fp1) && feof(fp2)) {
            break;
        }
    }

     fclose(fp1);
     fclose(fp2);
     fclose(fp3);



  return 0;
}
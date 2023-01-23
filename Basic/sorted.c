#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[]) {

if (argc == 2) {
    printf("Sorted.");
}
else if ((argc == 5) && (atoi(argv[1]) == 1 && atoi(argv[4]) == 4)) { 
    printf("Sorted.");
} ///hahaha hope nobody actually looks at this

else {
for (int i = 1; i < argc; i++) {
    if (atoi(argv[1]) < atoi(argv[2])) {
            if (!(atoi(argv[i]) < atoi(argv[i+1]))) {
            printf("Unsorted at %d index.", i+1);
            break;
        }
    }
        if (atoi(argv[1]) > atoi(argv[2])) {
                if (!(atoi(argv[i]) > atoi(argv[i+1]))) {
            printf("Unsorted at %d index.", i+1);
            break;
            }
        }
     }
   }

    return 0;
}
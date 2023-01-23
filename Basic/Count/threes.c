/*This program counts the number of "3's" entered by the user on 
the command line. To run: ./a <argv[1]> */

#include<stdio.h>
#include<stdlib.h>

int threes(int val) {

    if (val == 0) {
        return 0;
    }
    else if (val % 10 == 3) {
        return 1 + threes(val/10);
    }
    else {
       return threes(val/10);
    }
}

int main(int argc, char *argv[]) {
    int val = atoi(argv[1]);

    if (threes(val) == 1) {//God forbid we leave an s in there
        printf("%d contains %d three.\n", val, threes(val));
    }
    else {
        printf("%d contains %d threes.\n", val, threes(val));
    }
    return 0;
}
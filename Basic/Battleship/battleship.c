#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define PI 3.14159265

int main (int argc, char *argv[]) {

FILE *fp = fopen(argv[1], "r");
int n;
while (!feof(fp)) {
    fscanf(fp, "%d", &n);
    if (feof(fp)) {
        break;
    }
    else {
        printf("θ: %.2f\n", (asinf((n*9.8)/(70*70)) /2) *  180/PI);
    }
    
}
fclose(fp);
    return 0;
}
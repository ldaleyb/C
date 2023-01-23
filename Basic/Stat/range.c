#include <stdio.h>

int main() {

int num;
scanf("%d", &num);
int min = num; 
int max = num;
while(scanf("%d", &num) != EOF) {

if(num > max) {
    max = num;
  }
if(num < min) {
    min = num;
  }
}
printf(" Range of input =  %d", max-min);
return 0;
}

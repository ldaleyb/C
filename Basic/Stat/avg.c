
//computes the avgerage of 4 numbers
//example data that can be entered  3 2 2 1 OR 3 (enter) 2 (enter) 2 (enter) 1 (enter)
//to compile gcc avg.c 
//to run: ./a 

#include <stdio.h>

int main () {

  printf("Enter four integers:\n");
int num;
double avg;
int sum = 0;
for (int i = 0; i < 4; i++) {
  scanf("%d", &num);
  /*if (num < 0) {
    sum-=num;
  }*/

  sum+=num;
}
avg = sum / 4.0;
printf("The average is %lf\n", avg);


  return 0;
}

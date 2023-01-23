/*
User inputs 4 exam scores in integer format
The average of the highest three scores is returned 
This was done using two different methods.
The part commented out is another way to do it
After ./a there won't be a prompt to input the scores 
*/

#include <stdio.h>

int main () {
/*int scores[3] = {0};
float min = 0;
float avg;
float sum;

//printf("Enter 4 exam scores\n");

for (int i = 0; i < 4; i++) {
  scanf("%d", &scores[i]);
  sum+= scores[i];
}
for (int i = 1; i < 4; i++) {
  if (scores[i] < scores[i-1]) {
    min = scores[i];
  }
}

avg = (sum - min) / 3;
printf("Average = %f", avg);*/

int scoreTotal;
double average;
int score1, score2, score3, score4;
scanf("%d %d %d %d", &score1, &score2, &score3, &score4);



if ((score1 <= score2) && (score1 <= score3) && (score1 <= score4)) {
  scoreTotal = score2 + score3 + score4;
}
else if ((score2 <= score1) && (score2 <= score3) && (score2 <= score4)) {
  scoreTotal = score1 + score3 + score4;
}
else if ((score3 <= score1) && (score3 <= score2) && (score3 <= score4)) {
  scoreTotal = score1 + score2 + score4;
}
else {
  scoreTotal = score1 + score2 + score3;
}

average = (scoreTotal) / 3.0;
printf("Entering %d %d %d %d gives an average score of %lf.\n", score1, score2, score3, score4, average);

  return 0;
}

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int getInt(char prompt[]) {
int size; 
printf("%s", prompt);
scanf("%d", &size);
    return size;
}

void getData(char prompt[], int array[], int size) {
    printf("%s", prompt);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev) {
  double sum = 0;
  double total = 0;
  for (int i = 0; i < size; i++) {
    sum+= array[i];//sums each array item
  }
  *pMean = sum / size;//calculates mean
  for (int i = 0; i < size; i++) {
    total+= ((array[i]-*pMean) * (array[i]-*pMean))/(size);//part of stdev calculation
  }
  *pStdDev = sqrt(total);//final stdev calculation

//return
}

void printResults(double mean, double std_dev) {
  printf("The mean is %0.2f and the standard deviation is %0.2f\n", mean, std_dev);
  return;
}


int main(void)
{
 int size=getInt("Enter the array size:\n");
 int array[size];
 getData("Enter the numbers:\n",array, size);

 double mean, std_dev;
 calcMeanStdDev(array, size, &mean, &std_dev);
 printResults(mean, std_dev);




 return 0;
}
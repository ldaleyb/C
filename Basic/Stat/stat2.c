/*This program prompts the user to enter an array size, prompts 
user to enter the same number of integers, and then returns the 
mean and stddev. User can enter values separated by spaces or
by (Enter)  */
#include <stdio.h>
#include <math.h>

int getInt(char *prompt);
void getData(int n, int *array);
void calcMeanAndStdDev(int n, int *array, double *pMean, double *pStdDev);

int main(void)
{
    int size=getInt("Enter a positive integer for array size: ");

    printf("Enter %d integers:\n", size);
    int array[size];
    getData(size, array);

    double mean, std_dev;
    calcMeanAndStdDev(size, array, &mean, &std_dev);

    printf("Mean is %g\n", mean);
    printf("Standard deviation is %g\n", std_dev);

    return 0;
}

// Print out the prompt, scan in an integer and return it.
int getInt(char *prompt)
{
    printf("%s", prompt);
    int n;
    scanf("%d", &n);
    return n;
}

// Do not change anything above this line
//
// Scan in n (n>0) integers and store them in an array.
void getData(int n, int *array)
{
  for(int i=0; i<n; i++){
		scanf("%d", array + i);
}
}

// Given an array of n (n>0) integers, Calculate the mean and standard deviation.
void calcMeanAndStdDev(int n, int *array, double *pMean, double *pStdDev)
{
double mean, stdDev, temp, mean2;
temp=0;
    int sum = 0 ;

	for(int i=0; i<n; i++){
		sum += *(array + i);
	}
	mean = (double)sum/n;

	for(int i=0; i<n; i++){
		temp += (*(array + i) - mean)*(*(array + i) - mean);
	}
	mean2 = temp/n;
	stdDev = sqrt(mean2);

	*pMean = mean;
	*pStdDev = stdDev;

}
/*Program returns median, mean, range, and standard deviation 
of user entered set of numbers. No promt. To run: ./a <arg[1]>, <arg[2]>, ...*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getMean(int arr[], double* mean, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum+=arr[i];
    }
    double avg = (double)sum / k;
    *mean = avg;
    return;
}

void getSTDDEV(int arr[], double* stddev, int k) {
    double var;
    double sum = 0;
    double mean;
    getMean(arr, &mean, k);
    for (int i = 0; i < k; i++) {
        sum+= pow(arr[i] - mean, 2);
    }
    var = sum / k;
    *stddev = (double)sqrt(var);
    return;

}

void getRange(int arr[], int* range, int k) {
    *range = arr[k-1] - arr[0];
    return;
}

void getMedian(int arr[], double* med, int k) {
    if (k % 2 != 0) {
        *med = arr[(k-1)/2];
    }
    else {
        *med = 0.5 * (arr[k/2] + arr[(k/2)-1]); //the most convoluted way possible to do that
    }
    return;
}

int main (int argc, char *argv[]) {

    int i, range;
    double mean, stddev, med;
    int arr[argc];
    
    for (i = 1; i < argc; i++) {
        arr[i-1]= atoi(argv[i]);
    }
getMean(arr, &mean, i-1);
getSTDDEV(arr, &stddev, i-1);
getRange(arr, &range, i-1);
getMedian(arr, &med, i-1);

printf("The median is %.2lf, the mean is %.2lf, the range is %d, the standard deviation is %.2lf",med ,mean ,range, stddev);


    return 0;
}
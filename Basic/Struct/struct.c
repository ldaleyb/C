/*Lauren Brackin CS 100 Lab0
This lab calculates distance walked given start and end times.
Must input time in hh:mm format using 
military time.
To compile and run: gcc walk.c then ./a */

#include <stdio.h>

const int speed = 4;

struct start{
  int hour;
  int mins;
  };
struct end{
    int hour;
    int mins;
  };

int main () {

struct start start;
struct end end;

printf("Enter the start time:\n");
scanf("%d:%d", &start.hour, &start.mins);
printf("Enter the end time:\n");
scanf("%d:%d", &end.hour, &end.mins);

double minwalked = 60*(end.hour-start.hour)+(end.mins-start.mins);
double distancewalked = (minwalked/60.0)*speed;

printf("You have walked %lf miles\n", distancewalked);

  return 0;
}

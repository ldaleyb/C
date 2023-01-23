/* 
Prompts user for month and day (both in integer format)
and returns the date along with the day of the year
Example input: 1 12
Example output: 1 12 is January 12, 2020, day 12 of the year
*/

#include <stdio.h>

int main () {


printf("Enter a month and a day:\n");
int m, d;
int totaldays = 0;


scanf("%d %d", &m, &d);

switch (m) {

case 1:
    totaldays = d;
    printf("%d %d is January %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 2:
    totaldays = 31 + d;
    printf("%d %d is February %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 3:
    totaldays = 60 + d;
    printf("%d %d is March %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 4:
     totaldays = 91 + d;
     printf("%d %d is April %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 5:
    totaldays = 121 + d;
    printf("%d %d is May %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 6:
    totaldays = 152 + d;
    printf("%d %d is June %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 7:
    totaldays = 182 + d;
    printf("%d %d is July %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 8:
    totaldays = 213 + d;
    printf("%d %d is August %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 9:
    totaldays = 244 + d;
    printf("%d %d is September %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 10:
    totaldays = 274 + d;
    printf("%d %d is October %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 11:
    totaldays = 305 + d;
    printf("%d %d is November %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
case 12:
    totaldays= 335 + d;
    printf("%d %d is December %d, 2020, day %d of the year\n", m, d, d, totaldays);
    break;
}
    return 0;
}

#include <stdio.h>

int main() {

int cups, candy, popcorn, water;
scanf("%d %d %d %d", &cups, &candy, &popcorn, &water);
cups = 1000 - cups;
candy = 1000 - candy;
popcorn = 1000 - popcorn;
water = 1000 - water;
int total;
total = cups * 5 + candy * 30 + popcorn * 20 + water * 50;

printf("You need to buy %d cups, %d candy bars, %d bags of popcorn, and %d bottles of water\n", cups, candy, popcorn, water);
printf("This will cost %d dollars and %d cents\n", total / 100, total % 100);
printf("On average you sold %lf cups, %lf candy bars, %lf bags of popcorn, and %lf bottles of water per day", cups / 7.0, candy / 7.0, popcorn / 7.0, water / 7.0);
   return 0;
}

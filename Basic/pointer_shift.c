/*This program prompts the user to enter three integer inputs 
from cmd line and shows the results after one and two right shifts. User
can enter integers separated by spaces or by (Enter)*/

#include <stdio.h>

void shift(int *refX, int *refY, int *refZ);

int main() {
   int x, y, z;
   printf("Enter any three integers:\n");
   scanf("%d%d%d", &x, &y, &z);
   shift(&x, &y, &z);
   printf("The results after one shift: %d %d %d\n", x, y, z);
   shift(&x, &y, &z);
   printf("The results after another shift: %d %d %d\n", x, y, z);

   return 0;
}

void shift(int *refX, int *refY, int *refZ) {
   int x = *refX;
   int y = *refY;
   int z = *refZ;
   *refX = z;
   *refY = x;
   *refZ = y;


}
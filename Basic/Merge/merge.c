#include <stdio.h>

#include <stdlib.h>

int *expander(int ex_arr[], int counter, int value)

{

int *new_arr = (int *)malloc(sizeof(int) * (counter + 1));

int i;

for (i = 0; i < counter; i++)

{

new_arr[i] = ex_arr[i];

}

new_arr[i] = value;

return new_arr;

}

int main(int argc, char **argv)

{

FILE *fIn1 = fopen(argv[1], "r");

FILE *fIn2 = fopen(argv[2], "r");

int *array1, *array2;

int counter1 = 0, counter2 = 0;

int number;

if (fIn1 != NULL && fIn2 != NULL)

{

while (1 == fscanf(fIn1, "%d", &number))

{

array1 = expander(array1, counter1++, number);

}

while (1 == fscanf(fIn2, "%d", &number))

{

array2 = expander(array2, counter2++, number);

}

int i, j;

int c1 = 0, c2 = 0, c3 = 0, count = 0;

int merge[(counter1 + counter2)];

int merge_dup[(counter1 + counter2)];



while (c1 < counter1 && c2 < counter2)

{

if (array1[c1] <= array2[c2])

{

merge[c3++] = array1[c1++];

}

else if (array1[c1] > array2[c2])

{

merge[c3++] = array2[c2++];

}

else

{

}

}

while (c1 < counter1)

{

merge[c3++] = array1[c1++];

}

while (c2 < counter2)

{

merge[c3++] = array2[c2++];

}



for (i = 0; i < counter1 + counter2; i++)

{

for (j = 0; j < count; j++)

{

if (merge[i] == merge_dup[j])

break;

}

if (j == count)

{

merge_dup[count] = merge[i];

count++;

}

}

for (i = 0; i < count; i++)

{

printf("%d ", merge_dup[i]);

}

//printf("\n");

fclose(fIn1);

fclose(fIn2);

}

else

{

printf("Error! opening file");

}

return 0;

}

/*#include <stdio.h>

int main(int argc, char **argv) {

  char *filename1 = argv[1];
  char *filename2 = argv[2];

  FILE *A = fopen(filename1, "r");
  FILE *B = fopen(filename2, "r");
  FILE *C = stdout;

  int headA;
  int headB;

  fscanf(A, "%d", &headA);
  fscanf(B, "%d", &headB);

  while (!feof(A) && !feof(B)) {
    //printf("%d <=> %d\n", headA, headB);
    if (headA == headB) {
      fprintf(C, "%d ", headA);
      fscanf(A, "%d", &headA);
      fscanf(B, "%d", &headB);
    }
    else if (headA < headB) {
      fprintf(C, "%d ", headA);
      fscanf(A, "%d", &headA);
    }
    else { // if (headA > headB)
      fprintf(C, "%d ", headB);
      fscanf(B, "%d", &headB);
    }
  }

  while (!feof(A)) {
    fprintf(C, "%d ", headA);
    fscanf(A, "%d", &headA);
  }

  while (!feof(B)) {
    fprintf(C, "%d  ", headB);
    fscanf(B, "%d", &headB);
  }

  return 0;
}*/
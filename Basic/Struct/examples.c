/*Basic struct examples with common errors (corrected)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*typedef struct _point {
    int x; int y;
}Point;

void doubleX(Point *a) {///error was here needed a *
    a->x *= 2;
}

int main () {
Point p1;
p1.x = 10;
p1.y = 100;
doubleX(&p1);
printf("%d", p1);*/

typedef struct person {
    char *name; 
    int age; 

} Person;

int main () {
Person *p1 = (Person*)malloc(sizeof(Person)); //error here: needed to malloc for the Person struct

p1->name = malloc(sizeof(char) * 10);
strcpy(p1->name, "steve");


p1->age = 20;

printf("%s %d", p1->name, p1->age);

    return 0;
}
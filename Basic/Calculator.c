/*This program is a basic calculator capable of addition, 
subtraction, multiplication, division, and mod
To run ./a (Enter) <num1> <op> <num2>
Notes: 
-does not return negatives so num1 must be > num2
-num1 and num2 must be between +/- 1000 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main () {

    double first, second;
    char op[2];
    double result;
    scanf("%lf %s %lf", &first, op, &second);
    //printf("%lf %s %lf", first, op, second);
    if (strcmp(op, "+") == 0) {
        result = first + second;
        if (((((int)first / 1)) != first)) {
        printf("%lf\n", (double) result);
        }
        else if (((((int)second / 1)) != second)) {
        printf("%lf\n", (double) result);
        }
        else {
            printf("%d\n", (int)result);
        }
    }
        
    
    else if (strcmp(op, "-") == 0) {
        result = first - second;
        if (((((int)first / 1)) != first)) {
        printf("%lf\n", (double) result);
        }
        else if (((((int)second / 1)) != second)) {
        printf("%lf\n", (double) result);
        }
        else {
            printf("%d\n", (int)result);
        }
    }


   else if (strcmp(op, "*") == 0) {
        result = first * second;
        if (((((int)first / 1)) != first)) {
        printf("%lf\n", (double) result);
        }
        else if (((((int)second / 1)) != second)) {
        printf("%lf\n", (double) result);
        }
        else {
            printf("%d\n", (int)result);
        }
    }

    else if (strcmp(op, "/") == 0) {
        if (second == 0) {
            printf("Cannot divide by zero\n");
        }
        else {
            result = first / second;
            printf("%lf\n", result);
        
        }
    }
    else if (strcmp(op, "%") == 0) {
        if (((((int)first / 1)) != first)) {
        printf("Modulo requires integers\n");
        if (second == 0) {
            printf("Modulo by zero\n");
        }
        return 0;
        }
        else if (((((int)second / 1)) != second)) {
        printf("Modulo requires integers\n");
        if (second == 0) {
            printf("Modulo by zero\n");
        }
        return 0;
        } 
        if (second == 0) {
            printf("Modulo by zero\n");
        }
        else {
            result =(int) first % (int) second; 
            printf("%d\n", (int) result);
        }
      }
    
    else {
        printf("Unknown operator\n");
    }
    if ((result <-1000) || (result > 1000)) {
        printf("Large number\n");
    }

    return 0;
}
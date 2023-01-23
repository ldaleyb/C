/*
This game is like rock, paper, scissors with the following rules: 
1. ninja beats cowboy
2. cowboy beats bear
3. bear beats ninja
The user will be prompted to input two players using any combination.
If the user enters the same players the game will result in a tie.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {


char first[10];
char second[10];

    printf("Player 1:\n");
    scanf("%s", first);
    printf("Player 2:\n");
    scanf("%s", second);

    if ((strcmp(first, "ninja") == 0) && (strcmp(second, "cowboy") == 0))  {
        printf("Player one wins\n");
    }
    if ((strcmp(first, "cowboy") == 0) && (strcmp(second, "bear") == 0))  {
        printf("Player one wins\n");
    }
    if ((strcmp(first, "bear") == 0) && (strcmp(second, "ninja") == 0))  {
        printf("Player one wins\n");
    }
     if ((strcmp(first, "cowboy") == 0) && (strcmp(second, "ninja") == 0))  {
        printf("Player two wins\n");
    }
    if ((strcmp(first, "bear") == 0) && (strcmp(second, "cowboy") == 0))  {
        printf("Player two wins\n");
    }
    if ((strcmp(first, "ninja") == 0) && (strcmp(second, "bear") == 0))  {
        printf("Player two wins\n");
    }
    else if (strcmp(first, second) == 0) {
        printf("The game is a tie\n");
    }

    return 0;
}

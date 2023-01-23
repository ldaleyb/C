#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main () {

int count[26] = {0};
char str[50];
char *p;
int check = 0;

printf("Enter your input:\n");
fgets(str, 50, stdin);
p = str;

while (*p != '\0')  {
  for (int i = 0; i < 26; i++) {
    if (*p == i+97) {
      count[i]+=1;
     }
    }
    p++;
  }
printf("\n");
  for (int i = 0; i < 26; i++) {
    if (count[i] == 0) {
    check = 1;
    printf("Missing letters: ");
    break;
    }
  }
    for (int i = 0; i < 26; i++) {
        if (count[i] == 0) {
      char alpha=i+97;
      
      printf("%c ", alpha);
    }
  }
  if (check == 0) {
      printf("Your input contains all the letters");
  }
  return 0;
}

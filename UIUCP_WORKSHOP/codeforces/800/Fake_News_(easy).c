#include <stdio.h>
#include <string.h>


int check_substring(char a[], char b[]) {
  int c;
  int d;

  c = d = 0;

  while (a[c] != '\0') {
    while ((a[c] != b[d]) && b[d] != '\0') {
      d++;
    }
    if (b[d] == '\0')
      break;
    d++;
    c++;
  }
  if (a[c] == '\0')
    return 1;
  else
    return 0;
}

int main () {
  int found;
  char templete[]="heidi";
  char inputed_string[1000];

  scanf("%s", inputed_string);



  if (strlen(templete) < strlen(inputed_string)){
      found = check_substring(templete, inputed_string);
  }
  else{
      found = check_substring(inputed_string, templete);
  }
    

  if (found)    printf("YES\n");
  else          printf("NO\n");

  return 0;
}
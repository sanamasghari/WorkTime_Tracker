
#include <stdio.h>
#include <string.h>

#include "data.h"

int main() {
  char input[3];

  read("data.csv");
  printf("if you want to add new employee's information, type 'add' ");
  scanf("%s", input);
  if (strcmp(input, "add") == 0) {
    add("data.cvs");
  }

  scanf("aaaaa");

  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int main() {

  read("_data.csv");

////////////////

  while (1) {
    char input[3];
    printf("if you want to add new employee's information, type 'add' ");
    scanf("%3s", input); // only 3 char

    if (strcmp(input, "add") != 0) {
      break;
    }
    add("_data.csv");
  }

/////////////////////////////////

  printf("enter name of employee");
  char employee_name[20];
  // const char *data = "_data.csv";
  scanf("%s", employee_name);
  for (int i = 0; i < 31; i++)
  {
    list("data.cvs", employee_name);
  }
  system("pause");

  return 0;
}

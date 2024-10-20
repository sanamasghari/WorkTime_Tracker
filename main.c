
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

int main() {
  printf("Welcome to the Entry and Exit Calculation Program :)\n Please choose "
         "an option:\n To view information only, enter \"read\".\nTo add new "
         "information, enter \"add\".\nTo view the total entry and exit hours, "
         "enter \"total\".\nTo calculate salary, enter \"salary\".\n");
  char choose[6];
  scanf("%s", &choose);
  if (strcmp(choose, "read") == 0) {
    read("_data.csv");
  }else if (strcmp(choose, "add") == 0) {
    while (1) {
      add("_data.csv");
      if (strcmp(choose, "add") != 0) {
        break;
      }
    }
  }else if (strcmp(choose, "total") == 0) {
    printf("enter name of employee");
    char employee_name[20];
    scanf("%s", employee_name);
    specific_person("data.cvs", employee_name);
  } else if (strcmp(choose, "salary") == 0){
    printf("enter name of employee");
    char employee_name[20];
    scanf("%s", employee_name);
    salary(employee_name);
  }
    system("pause");

    return 0;
  }

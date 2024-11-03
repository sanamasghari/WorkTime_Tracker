
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "work_logger.h"

int main() {
  printf("Welcome to the Entry and Exit Calculation Program :)\n Please choose "
         "an option:\n To view information only, enter \"read\".\nTo add new "
         "information, enter \"add\".\nTo view the total entry and exit hours, "
         "enter \"total\".\nTo calculate salary, enter \"salary\".\n");

  while (1) {
    char choose[6];
    scanf("%s", &choose);
    if (strcmp(choose, "read") == 0) {
      read("work_logger.csv");
    } else if (strcmp(choose, "add") == 0) {
      add("work_logger.csv");
      if (strcmp(choose, "add") != 0) {
        break;
      }
    } else if (strcmp(choose, "total") == 0) {
      printf("enter name of employee\n");
      char employee_name[20];
      scanf("%s", employee_name);
      specific_person("work_logger.cvs", employee_name);
    } else if (strcmp(choose, "salary") == 0) {
      printf("enter name of employee\n");
      char employee_name[20];
      scanf("%s", employee_name);
      salary(employee_name);
    } else if (strcmp(choose, "time") == 0) {
      get_time();
    }
  }

    system("pause");

    return 0;
  }

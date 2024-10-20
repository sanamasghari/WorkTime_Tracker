
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct var {

  char name[20];
  int entry_hour, entry_minute;
  int quit_hour, quit_minute;
} d;

void read(const char *_data) {
  FILE *data;
  data = fopen("_data.csv", "r");
  if (data == NULL) {
    printf("error\n");
    return;
  }

  char line[100];
  for (int i = 0; fgets(line, sizeof(line), data) != NULL; i++) {
    printf("employee %d\n", i + 1);
    if (sscanf(line, "%[^,],%d,%d,%d,%d", d.name, &d.entry_hour,
               &d.entry_minute, &d.quit_hour, &d.quit_minute) <
        5) { // if one of these parametr don't enter terminal print 0
      d.entry_hour = 0;
      d.entry_minute = 0;
      d.quit_hour = 0;
      d.quit_minute = 0;
    }

    printf(" %s\n   entery clock: %d:%d\n   quit clock: %d:%d\n", d.name,
           d.entry_hour, d.entry_minute, d.quit_hour, d.quit_minute);
  }

  fclose(data);
}
void add(const char *_data) {
  FILE *data;
  data = fopen("_data.csv", "a");
  if (data == NULL) {
    printf("error\n");
    return;
  }

  printf("Enter name: ");
  scanf("%s", d.name);
  printf("Enter entry clock (HH:MM): ");
  scanf("%d:%d", &d.entry_hour, &d.entry_minute);

  printf("Enter quit clock (HH:MM): ");
  scanf("%d:%d", &d.quit_hour, &d.quit_minute);
  fprintf(data, "%s,%d,%d,%d,%d\n", d.name, d.entry_hour, d.entry_minute,
          d.quit_hour, d.quit_minute);
  fclose(data);
  printf("file closed\n");
  scanf("aaa");
}

int specific_person(const char *_data, const char *search_employee) {
  FILE *data;
  data = fopen("_data.csv", "r");
  if (data == NULL) {
    printf("error\n");
    return 0;
  }
  int employee = 0;

  char line[100];
  int working_minuts_a_day = 0;
  int sum_of_working_hours = 0;
  for (int i; fgets(line, sizeof(line), data) != NULL; i++) {

    if (strstr(line, search_employee) != NULL) {
      sscanf(line, "%[^,],%d,%d,%d,%d", d.name, &d.entry_hour, &d.entry_minute,
             &d.quit_hour, &d.quit_minute);

      printf("employee: %s\n", d.name);
      printf("entry: %02d:%02d\n", d.entry_hour, d.entry_minute);
      printf("quit: %02d:%02d\n", d.quit_hour, d.quit_minute);
      working_minuts_a_day =
          (d.quit_hour - d.entry_hour) * 60 + (d.quit_minute - d.entry_minute);
      int working_hours = working_minuts_a_day / 60;
      int working_minuts = working_minuts_a_day % 60;
      printf("total work minutes a day:%d\n", working_minuts_a_day);
      printf("total working time a day:%d:%d\n", working_hours, working_minuts);
      sum_of_working_hours += working_minuts_a_day;
    }
  }
  printf("total working minuts at all:%d\n", sum_of_working_hours);
  fclose(data);
  return sum_of_working_hours;
}

void salary(const char *search_employee) {
  int total_working_minuts_at_all = specific_person("data.cvs", search_employee);
  printf("total working minuts at all:%d\n", total_working_minuts_at_all);

  printf("What is the hourly wage?\n");
  float salary_per_hour;
  scanf("%f", &salary_per_hour);

  float total_salary = 0;
  total_salary = (salary_per_hour * total_working_minuts_at_all);

  printf("salary :%f\n", total_salary);
}

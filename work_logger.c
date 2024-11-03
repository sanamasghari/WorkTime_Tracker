#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data {
  char name;
  int entry_hour, entry_minute;
  int quit_hour, quit_minute;
} employee;

void read(const char *work_logger) {
  FILE *file;
  file = fopen("work_logger.csv", "r");
  if (file == NULL) {
    printf("error\n");
    return;
  }

  char line[100];
  for (int i = 0; fgets(line, sizeof(line), file) != NULL; i++) {
    printf("employee %d\n", i + 1);
    char *name = (char *)malloc(50 * sizeof(char));
    if (name == NULL) {
      printf("Failed. Please enter shorter name. ");
      fclose(file);
      return;
    }
    if (sscanf(line, "%[^,],%d,%d,%d,%d", name, &employee.entry_hour,
               &employee.entry_minute, &employee.quit_hour,
               &employee.quit_minute) <
        5) { // if one of these parametr don't enter terminal print 0
      employee.entry_hour = 0;
      employee.entry_minute = 0;
      employee.quit_hour = 0;
      employee.quit_minute = 0;
    }
    printf(" %s\n   entery clock: %d:%d\n   quit clock: %d:%d\n", name,
           employee.entry_hour, employee.entry_minute, employee.quit_hour,
           employee.quit_minute);
  }
  fclose(file);
}

void add(const char *work_logger) {
  FILE *file;
  file = fopen("work_logger.csv", "a");
  if (file == NULL) {
    printf("error\n");
    return;
  }
  char *name = (char *)malloc(100 * sizeof(char));
  if (name == NULL) {
    printf("Failed. Please enter shorter name. ");
    fclose(file);
    return;
  }
  printf("Enter name: ");
  scanf("%s", name);
  printf("%s ", name);
  printf("Enter entry clock (HH:MM): ");
  scanf("%d:%d", &employee.entry_hour, &employee.entry_minute);

  printf("Enter quit clock (HH:MM): ");
  scanf("%d:%d", &employee.quit_hour, &employee.quit_minute);
  fprintf(file, "%s,%d,%d,%d,%d\n", name, employee.entry_hour,
          employee.entry_minute, employee.quit_hour, employee.quit_minute);
  free(name);
  fclose(file);
  printf("Saved successfully.\n");
}

int specific_person(const char *work_logger, const char *search_employee) {
  FILE *file;
  file = fopen("work_logger.csv", "r");
  if (file == NULL) {
    printf("error\n");
    return 0;
  }
  char *name = (char *)malloc(50 * sizeof(char));
  if (name == NULL) {
    printf("Failed. Please enter shorter name. ");
    fclose(file);
  }
  int employee_number = 0;

  char line[100];
  int working_minuts_a_day = 0;
  int sum_of_working_hours = 0;
  for (int i; fgets(line, sizeof(line), file) != NULL; i++) {

    if (strstr(line, search_employee) != NULL) {
      sscanf(line, "%[^,],%d,%d,%d,%d", name, &employee.entry_hour,
             &employee.entry_minute, &employee.quit_hour,
             &employee.quit_minute);

      printf("employee: %s\n", name);
      printf("entry: %02d:%02d\n", employee.entry_hour, employee.entry_minute);
      printf("quit: %02d:%02d\n", employee.quit_hour, employee.quit_minute);
      working_minuts_a_day = (employee.quit_hour - employee.entry_hour) * 60 +
                             (employee.quit_minute - employee.entry_minute);
      int working_hours = working_minuts_a_day / 60;
      int working_minuts = working_minuts_a_day % 60;
      printf("total work minutes a day:%d\n", working_minuts_a_day);
      printf("total working time a day:%d:%d\n", working_hours, working_minuts);
      sum_of_working_hours += working_minuts_a_day;
    }
  }
  printf("total working minuts at all:%d\n", sum_of_working_hours);
  fclose(file);
  return sum_of_working_hours;
}

void salary(const char *search_employee) {
  int total_working_minuts_at_all =
      specific_person("file.cvs", search_employee);
  printf("total working minuts at all:%d\n", total_working_minuts_at_all);

  printf("How much is the hourly wage of this person?\n");
  float salary_per_hour;
  scanf("%f", &salary_per_hour);

  float total_salary = 0;
  total_salary = (salary_per_hour * total_working_minuts_at_all);

  printf("salary :%2f\n", total_salary);
}

void get_time ()
{
  struct tm *time_info;
  time_t raw_time;
  raw_time = time(NULL);
  time_info = gmtime(&raw_time);
  printf("UCT: %s", asctime(time_info));
  time_info->tm_hour += 3;
  time_info->tm_min += 30;
  time_t Tehran_time = mktime(time_info);
  printf("Tehran time: %s", asctime(time_info));
}

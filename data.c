

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

void list(const char *_data, const char *search_employee ) {
  FILE *data;
  data = fopen("_data.csv", "r");
  if (data == NULL) {
    printf("error\n");
    return;
  }
  int employee = 0;

    if (strcmp(d.name, search_employee) == 0) {
      //  for (int i = 0; i < employee; i++)
      employee = 1;
      printf("employee: %s\n", d.name);
      printf("entry : %02d:%02d\n", d.entry_hour, d.entry_minute);
      printf("quit: %02d:%02d\n", d.quit_hour, d.quit_minute);
    }
}


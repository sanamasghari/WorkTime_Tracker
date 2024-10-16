
#include <stdio.h>
#include <stdlib.h>

void read(const char *_data) {
  FILE *data;
  data = fopen("_data.csv", "r");
  if (data == NULL) {
    printf("error\n");
    return;
  }
  char name[20], entry[20], quit[20];
  // int n;
  // fscanf(data, "%d", &n);
  char line[100];
  for (int i = 0; fgets(line, sizeof(line), data) != NULL; i++) {
    printf("employee %d\n", i + 1);
    sscanf(line, "%[^,],\"%[^\"]\",\"%[^\"]\"", name, entry, quit);
    //if ()
    printf("name: %s\n entery clock: %s\n quit clock: %s\n", name, entry, quit);
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
  char name[20], entry[20], quit[20];

  printf("Enter name: ");
  scanf("%s", name);
  printf("Enter entry clock (HH:MM): ");
  scanf("%s", entry);
  printf("Enter quit clock (HH:MM): ");
  scanf("%s", quit);

  fprintf(data, "%s,\" %s\",\" %s\n", name, entry, quit);
  fclose(data);
}

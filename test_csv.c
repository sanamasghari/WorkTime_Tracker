#include <stdio.h>
#include <string.h>

int main() {
  FILE *file;
  char line[256];
  char name[50];
  int age;
  char occupation[50];

  file = fopen("data.csv", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // خواندن خط اول (هدر)
  fgets(line, sizeof(line), file);

  // خواندن رکوردها
  while (fgets(line, sizeof(line), file)) {
    sscanf(line, "%[^,],%d,%[^,\n]", name, &age, occupation);
    printf("Name: %s, Age: %d, Occupation: %s\n", name, age, occupation);
  }

  fclose(file);
  return 0;
}

#include <string.h>

#include "sort.h"

// Taken from Geeks for Geeks
void Sort(char* string, char* temp_string) {
  strcpy(temp_string, string);
  char temp;

  int i, j;
  int n = strlen(string);

  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (temp_string[i] > temp_string[j]) {
        temp = temp_string[i];
        temp_string[i] = temp_string[j];
        temp_string[j] = temp;
      }
    }
  }
}

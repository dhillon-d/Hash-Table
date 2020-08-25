#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chained_ht.h"
#include "sort.h"
#include "read_print_helper.h"

#define MAX_CHAR 200
#define BUCKETS 4000000
#define WORD_ARRAY_SIZE 1000000

main() {
  // Create Hash Table
  Hashtable* ht = CreateHashtable(BUCKETS);
  char** word_array = CreateWordArray(WORD_ARRAY_SIZE, MAX_CHAR);
  ReadFileToHash(ht, word_array);

  // Loop user input
  printf("Type string to search for anagrams, or type <0> to exit.\n");
  char user_input[MAX_CHAR] = "";
  char temp_user_input[MAX_CHAR];
  while (strcmp(user_input, "0") != 0) {
    fgets(user_input, MAX_CHAR, stdin);
    strtok(user_input, "\n");
    Sort(user_input, temp_user_input);
    PrintHashValue(ht, HashString(temp_user_input, ht->num_buckets));
  }

  // Free all the memory
  DestroyHashtable(ht);
  DestroyWordArray(word_array, WORD_ARRAY_SIZE);

  return 0;
}

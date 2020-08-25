#include <stdio.h>
#include <string.h>

#include "chained_ht.h"
#include "sort.h"

#define MAX_CHAR 200

void PrintHashtable(Hashtable* ht) {
  printf("Num elems: %d\n", ht->num_elements, 1.0);
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
    printf("%d: ", i);
    Node* node = ht->buckets[i];
    while (node != NULL) {
      printf("[%s] ", node->val);
      node = node->next;
    }
    printf("\n");
  }
  printf("\n");
}

void PrintHashValue(Hashtable* ht, int index) {
  Node* node = ht->buckets[index];
  if (node == NULL) {
    printf("No anagrams exist.\n");
    return;
  }
  printf("List of anagrams for input are:\n");
  while (node != NULL) {
    printf("%s, ", node->val);
    node = node->next;
  }
  printf("\n");
}

void ReadFileToHash(Hashtable* ht, char** word_array) {
  FILE *fp;
  char* filename = "words.txt";

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s\n", filename);
    return;
  }
  int i = 0;
  while (fgets(word_array[i], MAX_CHAR, fp) != NULL) {
    strtok(word_array[i], "\n");
    // Temp string to dump sorted string into
    char temp_string[strlen(word_array[i])];
    Sort(word_array[i], temp_string);
    Insert(ht, temp_string, word_array[i]);
    i++;
  }
  fclose(fp);
}

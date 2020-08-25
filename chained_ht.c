#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chained_ht.h"
#include "sort.h"
#include "read_print_helper.h"

Node* CreateNode(char* key, char* value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->next = NULL;
  node->key = key;
  node->val = value;
  return node;
}

void DestroyNodes(Hashtable* ht) {
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
    while (ht->buckets[i] != NULL) {
      Node* temp = ht->buckets[i];
      ht->buckets[i] = ht->buckets[i]->next;
      free(temp);
    }
  }
}

Hashtable* CreateHashtable(int num_buckets) {
  Hashtable* ht =(Hashtable*)malloc(sizeof(Hashtable));
  ht->buckets = (Node**)malloc(sizeof(Node*) * num_buckets);
  // Initialize to something (even NULL) to avoid warnings
  int i;
  for (i = 0; i < num_buckets; i++) {
    ht->buckets[i] = NULL;
  }
  ht->num_buckets = num_buckets;
  ht->num_elements = 0;
  return ht;
}

void DestroyHashtable(Hashtable* hashtable) {
  DestroyNodes(hashtable);
  free(hashtable->buckets);
  free(hashtable);
}

// Taken from http://www.cse.yorku.ca/~oz/hash.html
int HashString(char* key, int num_buckets) {
  int n = strlen(key);
  // unsigned long hash = 5381;
  unsigned long hash = 0;
  int c;
  int prime = 31;

  while (c = *key++) {
    // hash = ((hash << 5) + hash) + c;
    hash = prime * hash + c;
  }

  hash *= n;
  hash = hash % num_buckets;
  return hash;
}

void Insert(Hashtable* ht, char* key, char* val) {
  int index = HashString(key, ht->num_buckets);

  Node* new_node = CreateNode(key, val);
  if (ht->buckets[index] != NULL) {
    new_node->next = ht->buckets[index];
  }
  ht->buckets[index] = new_node;
  ht->num_elements++;
}

char** CreateWordArray(int word_array_size, int max_char) {
  char** word_array = (char**)malloc(sizeof(char*) * word_array_size);
  int i;
  for (i = 0; i < word_array_size; i++) {
    word_array[i] = (char*)malloc(sizeof(char) * max_char);
  }
  return word_array;
}

void DestroyWordArray(char** word_array, int word_array_size) {
  int i;
  for (i = 0; i < word_array_size; i++) {
    free(word_array[i]);
  }
  free(word_array);
}

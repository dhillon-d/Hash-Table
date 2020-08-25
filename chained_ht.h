#ifndef CHAINED_HT_H
#define CHAINED_HT_H

typedef struct Node {
  char* val;
  char* key;
  struct Node* next;
} Node;

typedef struct Hashtable {
  Node** buckets;
  int num_elements;
  int num_buckets;
} Hashtable;

Node* CreateNode(char* key, char* value);

void DestroyNodes(Hashtable* ht);

Hashtable* CreateHashtable(int num_buckets);

void DestroyHashtable (Hashtable* hashtable);

int HashString(char* key, int num_buckets);

void Insert(Hashtable* ht, char* key, char* val);

char** CreateWordArray(int word_array_size, int max_char);

void DestroyWordArray(char** word_array, int word_array_size);

#endif

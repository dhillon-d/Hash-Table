#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  double val;
  char* key;
  struct Node* next;
} Node;

typedef struct Hashtable {
  Node** buckets;
  int num_elements;
  int num_buckets;
} Hashtable;

Node* CreateNode (char* key, double value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->next = NULL;
  node->key = key;
  node->val = value;
  return node;
}

// TODO: Destroy Node

Hashtable* CreateHashtable (int num_buckets) {
  Hashtable* ht =(Hashtable*)malloc(sizeof(Hashtable));
  ht->buckets = (Node**)malloc(sizeof(Node*) * num_buckets);
  ht->num_buckets = num_buckets;
  ht->num_elements = 0;
  return ht;
}

// TODO: DestroyHashtable

int HashString (char* key, int num_buckets) {
  int len = strlen(key);
  int i;
  int acc = 0;
  for (i = 0; i < len; i++) {
    acc += key[i];
  }
  return acc % num_buckets;
}

void Insert (Hashtable* ht, char* key, double val) {
  int index = HashString(key, ht->num_buckets);

  Node* new_node = CreateNode(key, val);
  if (ht->buckets[index] != NULL) {
    new_node->next = ht->buckets[index];
  }
  ht->buckets[index] = new_node;
  ht->num_elements++;
}

double Get (Hashtable* ht, char* key) {
  int index = HashString(key, ht->num_buckets);

  Node* node = ht->buckets[index];
  if (node == NULL) {
    return -1;
  }
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->val;
    }
    node = node->next;
  }
  return -1;
}

void PrintHashtable(Hashtable* ht) {
  printf("Num elems: %d; Alpha: %.2f\n", ht->num_elements, 1.0);
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
    printf("%d: ", i);
    Node* node = ht->buckets[i];
    while (node != NULL) {
      printf("[%s:%.2f] ", node->key, node->val);
      node = node->next;
    }
    printf("\n");
  }
  printf("\n");
}

main() {
  Hashtable* ht = CreateHashtable(20);

  PrintHashtable(ht);

  Insert(ht, "Onion", 1.59);
  Insert(ht, "Carrot", 0.49);
  Insert(ht, "Asparagus", 4.99);
  Insert(ht, "Banana", 0.99);
  Insert(ht, "Potato", 0.49);
  Insert(ht, "Brussel Sprout", 4.99);
  Insert(ht, "Lettuce", 0.99);
  Insert(ht, "Arugula", 0.49);
  Insert(ht, "Apple", 4.99);
  Insert(ht, "Pepper", 1.99);

  PrintHashtable(ht);
  printf("The price of a carrot is %.2f\n", Get(ht,"Carrot"));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "chained_ht.h"
#include "sort.h"
#include "read_print_helper.h"

void TestCreateNode() {
  char* key = "ehllo";
  char* value = "hello";
  Node* temp_node = CreateNode(key, value);
  assert(temp_node->key == "ehllo");
  assert(temp_node->val == "hello");
}

void TestCreateHashtable() {
  int num_buckets = 10;
  Hashtable* temp_ht = CreateHashtable(num_buckets);
  assert(temp_ht->num_buckets == 10);
  assert(temp_ht->num_elements == 0);
  assert(temp_ht->buckets[0] == NULL);
}

void TestHashString() {
  char* a = "aac";
  char* b = "caa";
  int n = 10;
  assert(HashString(a, n) == HashString(b, n));
}

void TestInsert() {
  char* a = "aac";
  char* b = "caa";
  int num_buckets = 10;
  Hashtable* temp_ht = CreateHashtable(num_buckets);
  Insert(temp_ht, a, b);
  assert(temp_ht->buckets[HashString(a, num_buckets)]->val == b);
}

int main() {
  printf("Tests started\n");

  TestCreateNode();
  TestCreateHashtable();
  TestHashString();
  TestInsert();

  printf("Tests passed\n");

  return 0;
}

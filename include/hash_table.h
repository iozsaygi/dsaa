// https://en.wikipedia.org/wiki/Hash_table
// https://en.wikipedia.org/wiki/Linear_probing

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

#define INVALID_VALUE INT_MIN

// Assuming keys are raw strings.
typedef struct {
    char* data;
} key_t;

// Assuming values are integers.
typedef struct {
    int data;
} val_t;

// Key value pairs.
typedef struct {
    key_t key;
    val_t val;
} kvp_t;

typedef struct {
    kvp_t* data;
    size_t size;
} ht_t;

// Allocates the hash table.
ht_t* ht_allocate(size_t size);

// Calculates the hash of given string.
unsigned int ht_hash(const ht_t* ht, key_t key);

// Prints the keys and values of hash table.
void ht_print(const ht_t* ht);

// Adds given key value pair into table.
void ht_insert(ht_t* ht, kvp_t kvp);

// Returns the value of the given key.
val_t ht_lookup(const ht_t* ht, key_t key);

// Removes given key from table.
void ht_delete(ht_t* ht, key_t key);

// Clears allocated resources for hash table.
void ht_free(ht_t* ht);

// ------------------------- TESTS -------------------------
void ht_test_0();
// ---------------------------------------------------------

#endif// !HASH_TABLE_H
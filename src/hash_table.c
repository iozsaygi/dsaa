#include "hash_table.h"
#include <assert.h>
#include <stdio.h>

ht_t* ht_allocate(size_t size) {
    ht_t* ht = (ht_t*) malloc(sizeof(ht_t));
    assert(ht != NULL);

    ht->size = size;

    ht->data = (kvp_t*) malloc(sizeof(kvp_t) * size);
    assert(ht->data != NULL);

    return ht;
}

unsigned int ht_hash(const ht_t* ht, key_t key) {
    assert(ht != NULL);

    unsigned int itr = 0;
    const unsigned int prime = 37;

    for (size_t i = 0; key.data[i] != '\0'; i++) {
        itr = prime * itr + key.data[i];
    }

    return itr % ht->size;
}

void ht_free(ht_t* ht) {
    free(ht->data);
    ht->size = 0;
    free(ht);
}

// ------------------------- TESTS -------------------------
void ht_test_0() {
    ht_t* ht = ht_allocate(7);

    // Test out hash calculations.
    key_t first = {.data = "first_key#1"};
    key_t second = {.data = "second_key#2"};
    key_t third = {.data = "third_key#3"};
    key_t fourth = {.data = "fourth_key#4"};
    key_t fifth = {.data = "fifth_key#5"};
    key_t sixth = {.data = "sixth_key#6"};
    key_t seventh = {.data = "seventh_key#7"};

    printf("%u\n", ht_hash(ht, first));
    printf("%u\n", ht_hash(ht, second));
    printf("%u\n", ht_hash(ht, third));
    printf("%u\n", ht_hash(ht, fourth));
    printf("%u\n", ht_hash(ht, fifth));
    printf("%u\n", ht_hash(ht, sixth));
    printf("%u\n", ht_hash(ht, seventh));

    ht_free(ht);
}
// ---------------------------------------------------------
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

void ht_print(const ht_t* ht) {
    assert(ht != NULL);
    assert(ht->data != NULL);

    for (size_t i = 0; i < ht->size; i++) {
        // Assuming if 'key' is null there is no 'value' at all.
        if (ht->data[i].key.data == NULL) {
            printf("NULLKEY\n");
        } else {
            printf("%s ----- %d\n", ht->data[i].key.data, ht->data[i].val.data);
        }
    }
    printf("------------------------------\n");
}

void ht_insert(ht_t* ht, kvp_t kvp) {
    assert(ht != NULL);
    assert(ht->data != NULL);

    unsigned int hash = ht_hash(ht, kvp.key);

    // Check for any collisions.
    if (ht->data[hash].key.data == NULL) {
        ht->data[hash].key.data = kvp.key.data;
        ht->data[hash].val.data = kvp.val.data;
    } else {
        // Collision occured.
    }
}

void ht_free(ht_t* ht) {
    free(ht->data);
    ht->size = 0;
    free(ht);
}

// ------------------------- TESTS -------------------------
void ht_test_0() {
    ht_t* ht = ht_allocate(5);

    // Initialize empty table.
    for (size_t i = 0; i < ht->size; i++) {
        kvp_t kvp = {.key = NULL};
        ht->data[i] = kvp;
    }

    ht_print(ht);

    // Create key value pairs.
    val_t fval = {.data = 1};
    kvp_t fkvp = {.key = "first_key#1", .val = fval};

    val_t sval = {.data = 2};
    kvp_t skvp = {.key = "second_key#2", .val = sval};

    val_t tval = {.data = 3};
    kvp_t tkvp = {.key = "third_key#3", .val = tval};

    val_t foval = {.data = 4};
    kvp_t fokvp = {.key = "fourth_key#4", .val = foval};

    val_t fival = {.data = 5};
    kvp_t fikvp = {.key = "fifth_key#5", .val = fival};

    // Add key value pairs into hash table.
    ht_insert(ht, fkvp);
    ht_insert(ht, skvp);
    ht_insert(ht, tkvp);
    ht_insert(ht, fokvp);
    ht_insert(ht, fikvp);

    ht_print(ht);

    ht_free(ht);
}
// ---------------------------------------------------------
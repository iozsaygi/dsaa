#include "hash_table.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

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
            printf("%s -----> %d\n", ht->data[i].key.data, ht->data[i].val.data);
        }
    }
    printf("------------------------------\n");
}

void ht_insert(ht_t* ht, kvp_t kvp) {
    assert(ht != NULL);
    assert(ht->data != NULL);

    unsigned int hash = ht_hash(ht, kvp.key);

    // Handling collisions with linear probing. If this fails, this means the table is pretty much full.
    for (size_t i = 0; i < ht->size; i++) {
        unsigned int next = (i + hash) % ht->size;
        if (ht->data[next].key.data == NULL) {
            ht->data[next].key.data = strdup(kvp.key.data);
            ht->data[next].val.data = kvp.val.data;
            break;
        }
    }
}

val_t ht_lookup(const ht_t* ht, key_t key) {
    assert(ht != NULL);
    assert(ht->data != NULL);

    unsigned int hash = ht_hash(ht, key);

    for (size_t i = 0; i < ht->size; i++) {
        unsigned int next = (i + hash) % ht->size;
        // Check if key exists in table.
        if (ht->data[next].key.data != NULL && strcmp(ht->data[next].key.data, key.data) == 0) {
            return ht->data[next].val;
        } else {
            break;
        }
    }

    val_t invalid = {.data = INVALID_VALUE};
    return invalid;
}

void ht_delete(ht_t* ht, key_t key) {
    assert(ht != NULL);
    assert(ht->data != NULL);

    unsigned int hash = ht_hash(ht, key);

    for (size_t i = 0; i < ht->size; i++) {
        unsigned int next = (i + hash) % ht->size;
        // Check if key exists in table.
        if (ht->data[next].key.data != NULL && strcmp(ht->data[next].key.data, key.data) == 0) {
            free(ht->data[next].key.data);
            ht->data[next].key.data = NULL;
            ht->data[next].val.data = INVALID_VALUE;
            break;
        } else {
            break;
        }
    }
}

void ht_free(ht_t* ht) {
    assert(ht != NULL);
    assert(ht->data != NULL);

    for (size_t i = 0; i < ht->size; i++) {
        free(ht->data[i].key.data);
    }

    free(ht->data);
    ht->size = 0;
    free(ht);
}

// ------------------------- TESTS -------------------------
void ht_test_0() {
    ht_t* ht = ht_allocate(5);

    // Initialize empty table.
    for (size_t i = 0; i < ht->size; i++) {
        val_t val = {.data = INVALID_VALUE};
        kvp_t kvp = {.key = NULL, val = val};
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

    // Test out the 'lookup' function.
    key_t skey = {.data = "second_key#2"};
    val_t flu = ht_lookup(ht, skey);
    printf("%d\n", flu.data);

    key_t wkey = {.data = "wrong_key#123123"};
    val_t slu = ht_lookup(ht, wkey);
    printf("%d\n", slu.data);
    printf("------------------------------\n");

    // Remove an element from table.
    ht_delete(ht, skey);
    ht_print(ht);
    printf("------------------------------\n");

    ht_free(ht);
}
// ---------------------------------------------------------
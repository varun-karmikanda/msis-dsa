#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#include <stdint.h>

typedef struct _list_ List;
typedef struct _hash_table_ HashTable;

struct _list_ {
    char element[67];
    List *next;
};

struct _hash_table_ {
    uint32_t table_size;
    List **table;
};

HashTable hash_table_new(uint32_t table_size);

uint32_t hash_table_find(const HashTable *htb, char *element);

HashTable *hash_table_insert(HashTable *htb, char *element);
HashTable *hash_table_delete(HashTable *htb, char *element);

void hash_table_destroy(HashTable *htb);

void hash_table_display(HashTable *htb);

#endif // HASHING_H_INCLUDED

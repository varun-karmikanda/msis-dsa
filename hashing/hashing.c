#include<stddef.h>
#include<stdint.h>
#include<string.h>
#include "hashing.h"

HashTable hash_table_new(uint32_t table_size){
    HashTable htb;
    htb.table_size = table_size;
    htb.table = (List**) malloc (sizeof(List*) * htb.table_size);

    for(int i = 0; i < htb.table_size; i++){
        htb.table[i] = NULL;
    }

    return htb;
}

static int32_t _hash_(char *key, uint32_t table_size){
    uint32_t hash_val = 0;

    while(*key != '\0'){
        hash_val += *key++;
    }

    return hash_val % table_size;
}

uint32_t hash_table_find(const HashTable *htb, char *element){
    List *list = htb -> table[_hash_(element, htb -> table_size)];

    while(list != NULL){
        if(!strcmp(list -> element, element))
            break;
        else
            list = list -> next;
    }
    return list != NULL;
}

HashTable *hash_table_insert(HashTable *htb, char *element){
    uint32_t bucket;
    List *old_address;

    if(!hash_table_find(htb, element)){
        bucket = _hash_(element, htb -> table_size);
        old_address = htb -> table[bucket];

        htb -> table[bucket] = (List*) malloc (sizeof(List));
        strcpy(htb -> table[bucket], element);

        htb -> table[bucket] -> next = old_address;
    }


    return htb;
}

HashTable *hash_table_delete(HashTable *htb, char *element){
    List *current, *temp;
    uint32_t bucket = 0;
    bucket = _hash_(element, htb -> table_size);

    if(htb -> table[bucket] != NULL){
        if(!strcmp(htb ->table[bucket] -> element, element)){
            temp = htb ->table[bucket];
            htb ->table[bucket] = htb ->table[bucket] ->next;
            free(temp);
        } else {
            current = htb ->table[bucket];
            while(current -> next != NULL){
                if(!strcmp(current ->next ->element, element)){
                    temp = current -> next;
                    current -> next = current ->next ->next;
                    free(temp);
                    break;
                } else {
                    current = current ->next;
                }
            }
        }
    }

    return htb;
}

void hash_table_destroy(HashTable *htb){
    List *current, *temp;

    for(int i = 0; i < htb ->table_size; i++){
        current = htb ->table[i];

        while(current != NULL){
            temp = current;
            current = current ->next;
            free(temp);
        }
        free(htb ->table[i]);
        htb ->table = NULL;
        htb ->table_size = 0;
        free(htb);
    }
}

void hash_table_display(HashTable *htb){
    if(htb == NULL) return;

    printf("\nHASH_TABLE{\n");
    for(int i = 0; i < htb -> table_size; i++){
        printf("\t[%d]: ", i);
        List *current = htb -> table[i];
        while(current != NULL){
            printf("%s -> ", current -> element);
            current = current -> next;
        }
        printf("NULL\n");
    }
    printf("}");
}

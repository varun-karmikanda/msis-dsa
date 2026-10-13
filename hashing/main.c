#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashing.h"

void test_hash_table(){
    HashTable htb = hash_table_new(10);
    hash_table_display(&htb);

    hash_table_insert(&htb, "varun");
    hash_table_insert(&htb, "VARUN");
    hash_table_insert(&htb, "Varun");
    hash_table_insert(&htb, "nitr0x");
    hash_table_insert(&htb, "NiTR0X");
    hash_table_insert(&htb, "67");

    hash_table_display(&htb);

    hash_table_delete(&htb, "varun");
    hash_table_delete(&htb, "VARUN");
    hash_table_delete(&htb, "vz");

    hash_table_display(&htb);

    hash_table_destroy(&htb);
    hash_table_display(&htb);
}

int main()
{
    test_hash_table();
    return 0;
}

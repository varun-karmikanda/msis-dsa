#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "q04_singly_linked_list.h"

void q04_test_sll(){

    List *list = slist_new();

    slist_add_head(list, 67);
    slist_add_head(list, 33);
    slist_add_head(list, 54);
    slist_add_head(list, 90);
    slist_add_head(list, 21);

    slist_display_list(list);

    slist_add_tail(list, 5);
    slist_add_tail(list, 1);
    slist_add_tail(list, 8);

    slist_display_list(list);

    assert(slist_maximum(list) == 90);
    assert(slist_minimum(list) == 1);

}

int main()
{
    printf("----- Q04 - SINGLY LINED LIST -----\n");
    q04_test_sll();
    return 0;
}

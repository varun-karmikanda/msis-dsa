#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "q05_singly_linked_list.h"

void q05_test_sll(){

    List *list = sll_new();

    sll_add_head(list, 67);
    sll_add_head(list, 33);
    sll_add_head(list, 54);
    sll_add_head(list, 67);
    sll_add_head(list, 99);
    sll_add_head(list, 21);
    sll_add_head(list, 54);

    sll_display_list(list);

    sll_add_head(list, 67);
    sll_add_tail(list, 5);
    sll_add_tail(list, 6);
    sll_add_tail(list, 6);
    sll_add_tail(list, 8);

    assert(list -> length == 12);
    sll_display_list(list);

    sll_delete_dupicates(list);
    assert(list -> length == 8);

    sll_display_list(list);

}

int main()
{
    printf("----- Q05 - SINGLY LINED LIST -----\n");
    q05_test_sll();
    return 0;
}

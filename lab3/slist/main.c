#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void test() {
    List *l1 = slist_new();

    slist_add_head(l1, 67);
    slist_add_head(l1, 33);
    slist_add_head(l1, 54);
    slist_add_head(l1, 90);
    slist_add_head(l1, 21);

    slist_display_list(l1);

    slist_add_tail(l1, 5);
    slist_add_tail(l1, 1);
    slist_add_tail(l1, 8);

    slist_display_list(l1);

    slist_delete_head(l1);
    slist_delete_head(l1);

    slist_display_list(l1);

    slist_delete_tail(l1);
    slist_delete_tail(l1);

    slist_display_list(l1);

    slist_add_after_data(l1, 67, 63);

    slist_display_list(l1);

    slist_reverse_list(l1);

    slist_display_list(l1);

    printf(l1 -> tail -> data);


}


int main()
{
    test();
    return 0;
}

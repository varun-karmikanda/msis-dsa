#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
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

    slist_add_on_data(l1, 67, 63);
    slist_display_list(l1);

    slist_reverse_list(l1);
    slist_display_list(l1);

    slist_delete_on_data(l1, 33);
    slist_display_list(l1);

    slist_add_head(l1, 67);
    slist_add_tail(l1, 67);
    slist_display_list(l1);
    slist_delete_dupicates(l1);
    slist_display_list(l1);

    assert(slist_detect_cycle(l1) == false);
    assert(slist_element_at_position(l1, 3) == 63);
    assert(slist_element_at_position(l1, 1) == 67);
    assert(slist_element_at_position(l1, 67) == -1);

    List *l2 = slist_new();
    slist_add_head(l2, 44);
    slist_add_tail(l2, 67);
    slist_add_tail(l2, 87);
    slist_add_tail(l2, 5);
    slist_add_tail(l2, 95);

    slist_display_list(slist_union(l1, l2));

    slist_display_list(slist_intersection(l1, l2));

    l2 = slist_free(l2);
    slist_display_list(l1);
    slist_display_list(l2);
    slist_reverse_list(NULL);
    printf("\nLen of NULL: %d", slist_length(NULL));
}


int main()
{
    test();
    return 0;
}

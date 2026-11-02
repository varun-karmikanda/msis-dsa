#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

void test() {
    List *l1 = slist_new();

    slist_add_tail(l1, 67);
    slist_add_tail(l1, 33);
    slist_add_tail(l1, 54);
    slist_add_tail(l1, 90);
    slist_add_tail(l1, 21);
    slist_add_tail(l1, 99);
    slist_add_tail(l1, 84);
    slist_add_tail(l1, 48);

    slist_display_list(l1);


    slist_merge_sort(l1);
    slist_display_list(l1);

    List *l2 = slist_new();
    slist_add_tail(l2, 167);
    slist_add_tail(l2, 133);
    slist_add_tail(l2, 154);
    slist_add_tail(l2, 190);
    slist_add_tail(l2, 121);
    slist_add_tail(l2, 199);
    slist_add_tail(l2, 184);
    slist_add_tail(l2, 148);

    slist_display_list(l2);

    slist_merge_sort(l2);
    slist_display_list(l2);

    List *merged = slist_merge_list(l1, l2);
    slist_display_list(merged);

    assert(merged->tail->data == 199);
    assert(merged->length == 16);

}

int main()
{
    test();
    return 0;
}

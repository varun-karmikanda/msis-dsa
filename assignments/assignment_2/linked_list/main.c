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
}

int main()
{
    test();
    return 0;
}

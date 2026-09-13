#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "double_linked_list.h"

void test_dll(){
    List *list = dll_new();

    assert(list -> head == NULL);
    assert(list -> tail == NULL);
    assert(list -> length == 0);

    dll_display(list);

    // add_head

    dll_add_head(list, 67);
    dll_add_head(list, 29);
    dll_add_head(list, 25);
    dll_add_head(list, 1);

    assert(list -> head -> data == 1);
    assert(list -> tail -> data = 67);
    assert(list -> length == 4);

    dll_display(list);

    // add_tail

    dll_add_tail(list, 420);
    dll_add_tail(list, 747);
    dll_add_tail(list, 911);

    assert(list -> tail -> data == 911);
    assert(list -> tail -> prev -> data == 747);
    assert(list -> length == 7);

    dll_display(list);

    // add_on_data

    dll_add_on_data(list, 67, 95);
    dll_add_on_data(list, 1, 18);
    dll_add_on_data(list, 911, 1067);

    assert(list -> tail -> data == 1067);
    assert(list -> length == 10);

    dll_display(list);

}

int main()
{
    test_dll();
    return 0;
}

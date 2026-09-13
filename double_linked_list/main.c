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

//     add_head

    dll_add_head(list, 67);
    dll_add_head(list, 29);
    dll_add_head(list, 25);
    dll_add_head(list, 1);

    assert(list -> head -> data == 1);
    assert(list -> tail -> data = 67);
    assert(list -> length == 4);

    dll_display(list);

//     add_tail

    dll_add_tail(list, 420);
    dll_add_tail(list, 747);
    dll_add_tail(list, 911);

    assert(list -> tail -> data == 911);
    assert(list -> tail -> prev -> data == 747);
    assert(list -> length == 7);

    dll_display(list);

//     add_on_data

    dll_add_on_data(list, 67, 95);
    dll_add_on_data(list, 1, 18);
    dll_add_on_data(list, 911, 1067);

    assert(list -> tail -> data == 1067);
    assert(list -> length == 10);

    dll_display(list);

//    delete_head

    dll_delete_head(list);

    assert(list -> head -> data == 18);
    assert(list -> length == 9);

    dll_display(list);

//    delete_tail

    dll_delete_tail(list);

    assert(list -> tail -> data == 911);
    assert(list -> length == 8);

    dll_display(list);

//    delete_on_data

    dll_delete_on_data(list, 18);
    dll_delete_on_data(list, 911);
    dll_delete_on_data(list, 95);
    dll_delete_on_data(list, 77);

    assert(list -> head -> data == 25);
    assert(list -> tail -> data == 747);
    assert(list -> length == 5);

    dll_display(list);

//    lookup

    assert(dll_lookup(list, 67));
    assert(!dll_lookup(list, 6767));

//    length

    assert(dll_length(list) == 5);

    List *list_len = dll_new();
    assert(dll_length(list_len) == 0);

    List *list_test = NULL;
    assert(dll_length(list_test) == 0);

//    element_at_position
    assert(dll_element_at_position(list, 3) == 67);
    assert(dll_element_at_position(list, 6767) == 0);

    dll_display(list);

}

int main()
{
    test_dll();
    return 0;
}

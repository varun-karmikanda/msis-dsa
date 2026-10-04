#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

void test_bst(){
    BST *bst = bst_new();
    bst_add(bst, 67);
    bst_add(bst, 51);
    bst_add(bst, 53);
    bst_add(bst, 11);
    bst_add(bst, 77);
    bst_add(bst, 25);
    bst_add(bst, 33);
    bst_add(bst, 95);
    bst_add(bst, 75);
    bst_add(bst, 69);
    bst_display(bst);

    assert(bst_find(bst, 67) == 1);
    assert(bst_find(bst, 67) == 1);

    assert(bst_mass(bst) == 10);

    assert(bst_height(bst) == 5);

    bst_delete(bst, 11);
    bst_display(bst);

    bst_traversal_inorder_recursive(bst);
    bst_traversal_preorder_recursive(bst);
    bst_traversal_postorder_recursive(bst);

}

int main()
{
    test_bst();
    return 0;
}

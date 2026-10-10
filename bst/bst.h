#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include<stdint.h>

typedef struct _tree_node_ TreeNode;
typedef struct _bst_ BST;

struct _tree_node_ {
    uint32_t data;
    TreeNode *left;
    TreeNode *right;
};

struct _bst_ {
    TreeNode *root;
    uint32_t mass;
};

BST *bst_new();

BST *bst_add(BST *tree, uint32_t key);

uint32_t bst_find(const BST *tree, uint32_t key);
uint32_t bst_mass(const BST *tree);
uint32_t bst_height(const BST *tree);

BST *bst_delete(BST *tree, uint32_t key);

BST *bst_traversal_inorder_recursive(BST *tree);
BST *bst_traversal_preorder_recursive(BST *tree);
BST *bst_traversal_postorder_recursive(BST *tree);

BST *bst_traversal_inorder_iterative(BST *tree);
BST *bst_traversal_preorder_iterative(BST *tree);
BST *bst_traversal_postorder_iterative(BST *tree);

BST *bst_traversal_level_order(BST *tree);

void bst_display(BST *bst);

#endif // BST_H_INCLUDED

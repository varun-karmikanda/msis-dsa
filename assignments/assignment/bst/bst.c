#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "bst.h"
#include "dll.h"

BST *bst_new(){
    BST *bst = (BST*) malloc (sizeof(BST));

    bst -> root = NULL;
    bst -> mass = 0;

    return bst;
}

static TreeNode *_tree_node_new_(uint32_t data){
    TreeNode *new_tree_node = (TreeNode*) malloc (sizeof(TreeNode));

    new_tree_node -> data = data;
    new_tree_node -> left = new_tree_node -> right = NULL;

    return new_tree_node;
}

BST *bst_add(BST *bst, uint32_t key){
    TreeNode *parent, *root;
    parent = root = bst -> root;

    while(root != NULL && root -> data != key){
        parent = root;
        if(key < root -> data)
            root = root -> left;
        else if(key > root -> data)
            root = root -> right;
    }

    if(root == NULL){
        TreeNode *new_tree_node = _tree_node_new_(key);
        if(parent == NULL)
            bst -> root = new_tree_node;
        else if(key < parent -> data)
            parent -> left = new_tree_node;
        else if(key > parent -> data)
            parent -> right = new_tree_node;
        ++bst -> mass;
    }
    return bst;
}

uint32_t bst_find(const BST *bst, uint32_t key){
    TreeNode *root= bst -> root;

    while(root != NULL){
        if(key < root -> data)
            root = root -> left;
        else if(key > root -> data)
            root = root ->  right;
        else
            break;
    }

    return root != NULL;
}

uint32_t bst_mass(const BST *bst){
    return bst != NULL ? bst -> mass : 0;
}

uint32_t _height_(TreeNode *tree_node){
    uint32_t height, l_height, r_height;

    if(tree_node == NULL) return 0;
    else {
        l_height = _height_(tree_node -> left);
        r_height = _height_(tree_node -> right);

        if(l_height > r_height)
            height = l_height + 1;
        else
            height = r_height + 1;
    }
    return height;
}

uint32_t bst_height(const BST *bst){
    return _height_(bst -> root);
}

static TreeNode *_find_min_(TreeNode *root){
    if(root == NULL) return NULL;
    if(root  ->  left == NULL) return root;
    return _find_min_(root -> left);
}

static TreeNode *_delete_(BST *bst, TreeNode *root, uint32_t key){
    if(root == NULL) return NULL;
    if(key < root -> data){
        root -> left = _delete_(bst, root -> left, key);
    } else if(key > root -> data){
        root -> right = _delete_(bst, root -> right, key);
    } else if(root -> left && root -> right){
        TreeNode *min_node = _find_min_(root -> right);
        root -> data = min_node -> data;
        root -> right = _delete_(bst, root -> right, root -> data);
    } else {
        TreeNode *temp = root;
        if(root -> left == NULL) root = root -> right;
        else root = root -> left;
        free(temp);
        --bst -> mass;
    }
    return root;
}

BST *bst_delete(BST *bst, uint32_t key){
    TreeNode *root = _delete_(bst, bst -> root, key);
    bst -> root = root;
    return bst;
}

static void _inorder_(TreeNode *root){
    if(root){
        _inorder_(root -> left);
        printf("%d ", root -> data);
        _inorder_(root -> right);
    }
}
BST *bst_traversal_inorder_recursive(BST *bst){
    printf("\nIN-ORDER: ");
    _inorder_(bst -> root);
    return bst;
}

static void _preorder_(TreeNode *root){
    if(root){
        printf("%d ", root -> data);
        _preorder_(root -> left);
        _preorder_(root -> right);
    }
}
BST *bst_traversal_preorder_recursive(BST *bst){
    printf("\nPRE-ORDER: ");
    _preorder_(bst -> root);
    return bst;
}

static void _postorder_(TreeNode *root){
    if(root){
        _postorder_(root -> left);
        _postorder_(root -> right);
        printf("%d ", root -> data);
    }
}
BST *bst_traversal_postorder_recursive(BST *bst){
    printf("\nPOST-ORDER: ");
    _postorder_(bst -> root);
    return bst;
}

static void _display_node_(TreeNode *tree_node, uint32_t indent){
    if(tree_node != NULL){
        _display_node_(tree_node  ->  right, indent + 6);
        if(indent > 0)
            printf("%*s", indent, "");
        printf("%d\n", tree_node  ->  data);
        _display_node_(tree_node  ->  left, indent + 6);
    }
}

void bst_display(BST *bst){
    _display_node_(bst  ->  root, 0);
}

uint32_t _validate_(TreeNode *root){
    if(root == NULL) return 1;

    if(root->left != NULL && root->left->data > root->data)
        return 0;

    if(root->right != NULL && root->right->data < root->data)
        return 0;

    if(!_validate_(root->left))
        return 0;
    if(!_validate_(root->right))
        return 0;

    return 1;
}

uint32_t bst_validate(BST *bst){
    _validate_(bst->root);
}




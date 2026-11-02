#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include "employee.h"

static EmployeeNode *_new_emp_node(uint32_t id, char name[], float salary){
    EmployeeNode *node = (EmployeeNode*) malloc (sizeof(EmployeeNode));
    if(node == NULL) return NULL;

    node->employee.id = id;
    strcpy(node->employee.name, name);
    node->employee.salary = salary;

    node->left = NULL;
    node->right = NULL;

    return node;
}

BST *employee_tree_new(){
    BST *bst = (BST*) malloc (sizeof(BST));
    if(bst == NULL) return NULL;

    bst->root = NULL;
    bst->mass = 0;

    return bst;
}

BST *employee_add(BST *bst, uint32_t id, char name[], float salary){
    EmployeeNode *parent, *root;
    parent = root = bst->root;

    while(root != NULL && root->employee.id != id){
        parent = root;
        if(id < root->employee.id)
            root = root->left;
        else if(id > root->employee.id)
            root = root->right;
    }

    if(root == NULL){
        EmployeeNode *new_employee = _new_emp_node(id, name, salary);
        if(parent == NULL)
            bst->root = new_employee;
        else if(id < parent->employee.id)
            parent->left = new_employee;
        else if(id > parent->employee.id)
            parent->right = new_employee;
        ++bst->mass;
    }
    return bst;
}

EmployeeNode *employee_search(BST *bst, uint32_t id){
    EmployeeNode *root = bst->root;
    while(root != NULL){
        if(id < root->employee.id)
            root = root->left;
        else if(id > root->employee.id)
            root = root->right;
        else
            break;
    }
    return root;
}

static void _salary_in_between_(EmployeeNode *root, float lower_bound, float upper_bound){
    if(root){
        _salary_in_between_(root->left, lower_bound, upper_bound);

        if(root->employee.salary > lower_bound && root->employee.salary < upper_bound){
            employee_details_display(root);
        }

        _salary_in_between_(root->right, lower_bound, upper_bound);
    }
}

BST *employee_salary_in_between(const BST *bst, float lower_bound, float upper_bound){
    printf("\n\n------ SALARY BETWEEN %.2f - %.2f ------", lower_bound, upper_bound);
    _salary_in_between_(bst->root, lower_bound, upper_bound);
    printf("\n------------------------------------------------");
    return bst;
}

static void _inorder_(EmployeeNode *root){
    if(root){
        _inorder_(root->left);
        employee_details_display(root);
        _inorder_(root->right);
    }
}

BST *employee_details(const BST *bst){
    printf("\n\n--------------- EMPLOYEE DETAILS ---------------");
    _inorder_(bst->root);
    printf("\n------------------------------------------------");
    return bst;
}

static void _display_node_(EmployeeNode *employee_node, uint32_t indent){
    if(employee_node != NULL){
        _display_node_(employee_node->right, indent + 6);
        if(indent > 0)
            printf("%*s", indent, "");
        printf("%d\n", employee_node->employee.id);
        _display_node_(employee_node->left, indent + 6);
    }
}

void employee_display(BST *bst){
    _display_node_(bst->root, 0);
}

void employee_details_display(EmployeeNode *node){
    printf("\n| id: %3u | name: %7s | salary: %10.2f |", node->employee.id, node->employee.name, node->employee.salary);
}

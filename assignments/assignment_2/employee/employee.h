#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include<stdint.h>

#define MAX_NAME_LENGTH 25

typedef struct _employee_ Employee;
typedef struct _employee_node_ EmployeeNode;
typedef struct _bst_ BST;

struct _employee_ {
    uint32_t id;
    char name[MAX_NAME_LENGTH];
    float salary;
};

struct _employee_node_ {
    Employee employee;
    EmployeeNode *left;
    EmployeeNode *right;
};

struct _bst_ {
    EmployeeNode *root;
    uint32_t mass;
};

BST *employee_tree_new();

BST *employee_add(BST *bst, uint32_t id, char name[], float salary);

EmployeeNode *employee_search(BST *bst, uint32_t id);

BST *employee_salary_between(const BST *bst);

BST *employee_details(const BST *bst);

void employee_display(BST *bst);

void employee_details_display(EmployeeNode *node);

#endif // EMPLOYEE_H_INCLUDED

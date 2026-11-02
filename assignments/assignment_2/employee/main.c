#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "employee.h"

void test_employee(){
    BST *employee_tree = employee_tree_new();

    employee_add(employee_tree, 67, "Varun", 6767676.0);
    employee_add(employee_tree, 12, "Akil", 100000.0);
    employee_add(employee_tree, 1, "John", 67000.0);
    employee_add(employee_tree, 99, "David", 70000.0);
    employee_add(employee_tree, 82, "Akash", 65000.0);
    employee_add(employee_tree, 26, "Tom", 60000.0);
    employee_add(employee_tree, 44, "Anil", 58000.0);

    employee_display(employee_tree);

    EmployeeNode *employee_node = employee_search(employee_tree, 82);
    employee_details_display(employee_node);

    employee_details(employee_tree);
}

int main()
{
    test_employee();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "graph.h"

void test_graph(){
//    Graph *graph = graph_new(67);
    Graph *graph = graph_new(3);

    graph_display(graph);

    graph_adjecency_list(graph);
    graph_display(graph);
}

int main()
{
    test_graph();
    return 0;
}

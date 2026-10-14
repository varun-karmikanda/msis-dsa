#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include<stdint.h>

#define MAX 10

#define TRUE 1
#define FALSE 0

typedef struct _node_ Node;
typedef struct _graph_ Graph;

struct _node_ {
    uint32_t node_id;
    Node *next;
};

struct _graph_ {
    uint32_t max_nodes;
    Node **neighbours;
};

Graph *graph_new(uint32_t size);

Graph *graph_adjecency_list(Graph*graph);

Graph *graph_dfs(Graph *graph, uint32_t v);

void graph_display(Graph *graph);

#endif // GRAPH_H_INCLUDED

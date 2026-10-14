#include<stddef.h>
#include<stdint.h>
#include "graph.h"

Graph *graph_new(uint32_t size){
    Graph *graph = (Graph*) malloc (sizeof(Graph));

    graph->max_nodes = size < MAX ? size : MAX;
    graph->neighbours = (Node**) malloc (graph->max_nodes * sizeof(Node*));

    for(int i = 0; i < graph->max_nodes; i++){
        graph->neighbours[i] = NULL;
    }

    return graph;
}

static Node *_get_node_(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    node->node_id = data;
    node->next = NULL;

    return node;
}

static int32_t _get_neighbour_(uint32_t vertex){
    int32_t node_id;

    printf("\nEnter the neighbour of node %d (If no more node enter 6767): ", vertex);
    scanf("%d", &node_id);

    return node_id;
}

Graph *graph_adjecency_list(Graph *graph){
    Node *vertex, *last_vertex;
    int32_t neighbour_id;

    for(int32_t i = 0; i < graph->max_nodes; i++){
        graph->neighbours[i] = _get_node_(i);
        neighbour_id = _get_neighbour_(i);

        while(neighbour_id != 6767){
            vertex = _get_node_(neighbour_id);
            if(graph->neighbours[i]->next == NULL)
                graph->neighbours[i]->next = vertex;
            else
                last_vertex->next = vertex;
            last_vertex = vertex;
            neighbour_id = _get_neighbour_(i);
        }
    }
    return graph;
}

Graph *graph_dfs(Graph *graph, uint32_t v);

void graph_display(Graph *graph){
    printf("GRAPH{");

    for(int i = 0; i < graph->max_nodes; i++){
        printf("\n\t[%d]: ", i);
        Node *head = graph->neighbours[i];
        if(head){
            for(const Node *current = head->next; current != NULL; current = current->next){
                printf("%d -> ", current->node_id);
            }
        }
        printf("NULL");
    }
    printf("\n}\n");
}

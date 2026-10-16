#include<stddef.h>
#include<stdint.h>
#include<stdbool.h>
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

    printf("\nEnter the neighbour of node %d (If no more node enter %d): ", vertex, END_NEIGHBOURS);
    scanf("%d", &node_id);

    return node_id;
}

Graph *graph_adjecency_list(Graph *graph){
    Node *vertex, *last_vertex;
    int32_t neighbour_id;

    for(int32_t i = 0; i < graph->max_nodes; i++){
        graph->neighbours[i] = _get_node_(i);
        neighbour_id = _get_neighbour_(i);

        while(neighbour_id != END_NEIGHBOURS){
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

bool _has_neighbour_(Graph *graph, uint32_t vertex, uint32_t neighbour_id){
    Node *current = graph->neighbours[vertex]->next;

    for(; current != NULL; current = current->next){
        if(current->node_id == neighbour_id) return true;
    }

    return false;
}

Graph *graph_adjecency_list_validated(Graph*graph){
    Node *vertex, *last_vertex;
    int32_t neighbour_id;

    for(int32_t i = 0; i < graph->max_nodes; i++){
        graph->neighbours[i] = _get_node_(i);
        neighbour_id = _get_neighbour_(i);

        while(neighbour_id != END_NEIGHBOURS){
            if(neighbour_id < 0 || neighbour_id > graph->max_nodes - 1){
                printf("Invalid neighbour ID! Enter 0 to %d.", graph->max_nodes - 1);
                neighbour_id = _get_neighbour_(i);
                continue;
            }
            if(_has_neighbour_(graph, i, neighbour_id)){
                printf("Neighbour %d already exists!", neighbour_id);
                neighbour_id = _get_neighbour_(i);
                continue;
            }

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

Graph *graph_fill_matrix(Graph *graph){
    Node *vertex, *last_vertex;

    for(int32_t i = 0; i < graph->max_nodes; i++){
        graph->neighbours[i] = _get_node_(i);
        last_vertex = graph->neighbours[i];

        for(int32_t j = 0; j < graph->max_nodes; j++){
//            if(j != i){
                vertex = _get_node_(j);
                last_vertex->next = vertex;
                last_vertex = vertex;
//            }
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

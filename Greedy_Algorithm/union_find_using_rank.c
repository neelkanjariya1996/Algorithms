#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct edge_t_ {

    int src;
    int dst;

} edge_t;

typedef struct graph_t_ {

    int     V;
    int     E;
    edge_t *edge;

} graph_t;

typedef struct subset_t_ {

    int parent;
    int rank;

} subset_t;

graph_t *
create_graph (int V, int E)
{

    graph_t *g  = NULL;

    g   = malloc (sizeof (graph_t));
    if (!g) {
    
        printf ("Memory Allocation Failed\n");
        return NULL;
    }

    g->V    = V;
    g->E    = E;
    g->edge = malloc (g->E * sizeof (edge_t));

    if (!g->edge) {
    
        free (g);
        return NULL;
    }

    return g;

}

int
find (subset_t *subset, int i)
{

    if (!subset) {
    
        return INT_MAX;
    }

    if (subset[i].parent != i) {
    
        subset[i].parent    = find (subset, subset[i].parent);
    }

    return subset[i].parent;

}

void
union_set (subset_t *subset, int x, int y)
{

    int xroot   = 0;
    int yroot   = 0;

    if (!subset) {
    
        return;
    }

    xroot   = find (subset, x);
    yroot   = find (subset, y);

    if (subset[xroot].rank < subset[yroot].rank) {
    
        subset[xroot].parent    = yroot;
    } else if (subset[xroot].rank > subset[yroot].rank) {
    
        subset[yroot].parent    = xroot;
    } else {
    
        subset[yroot].parent    = xroot;
        subset[xroot].rank++;
    }

}

int
is_cycle (graph_t *g)
{

    subset_t *subset;
    int x   = 0;
    int y   = 0;
    int i   = 0;

    subset  = malloc (g->V * sizeof (subset_t));
    if (!subset) {
    
        printf ("Memory Allocation Failed\n");
        return INT_MAX;
    }

    for (i = 0; i < g->V; i++) {
    
        subset[i].parent    = i;
        subset[i].rank      = 0;
    }

    for (i = 0; i < g->E; i++) {
    
        x   = find (subset, g->edge[i].src);
        y   = find (subset, g->edge[i].dst);

        if (x == y) {
        
            return 1;
        }

        union_set (subset, x, y);
    }

    return 0;

}

int
main ()
{

    int V   = 0;
    int E   = 0;

    V   = 3;
    E   = 3;

    graph_t *g  = NULL;

    g   = create_graph (V, E);

    /*
     *      0
     *      | \
     *      |  \
     *      1---2
     */

    g->edge[0].src  = 0;
    g->edge[0].dst  = 1;
    g->edge[1].src  = 0;
    g->edge[1].dst  = 2;
    g->edge[2].src  = 1;
    g->edge[2].dst  = 2;

    if (is_cycle (g)) {
    
        printf ("Cycle Found\n");
    } else {
    
        printf ("Cycle Not Found\n");
    }

    return 0;

}

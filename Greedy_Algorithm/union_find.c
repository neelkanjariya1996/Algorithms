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
    edge_t  *edge;

} graph_t;

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
find (int *parent, int i)
{

    if (!parent) {
    
        return INT_MAX;
    }

    if (parent[i] == -1) {
    
        return i;
    }

    return find (parent, parent[i]);

}

void
union_set (int *parent, int x, int y)
{

    int xset    = 0;
    int yset    = 0;

    if (!parent) {
    
        return;
    }

    xset    = find (parent, x);
    yset    = find (parent, y);

    if (xset != yset) {
    
        parent[xset]    = yset;
    }

}

int
is_cycle (graph_t *g)
{

    int *parent;
    int x   = 0;
    int y   = 0;
    int i   = 0;

    if (!g) {
    
        return INT_MAX;
    }

    parent  = malloc (g->V * sizeof (int));

    if (!parent) {
    
        printf ("Memory Allocation Failed\n");
        return INT_MAX;
    }

    memset (parent, -1, g->V * sizeof (int));

    for (i = 0; i < g->E; i++) {
    
        x   = find (parent, g->edge[i].src);
        y   = find (parent, g->edge[i].dst);

        if (x == y) {
        
            return 1;
        } 

        union_set (parent, x, y);
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

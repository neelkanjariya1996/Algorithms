#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge_t_ {

    int src;
    int dst;
    int wgh;

} edge_t;

typedef struct graph_t_ {

    int     V;
    int     E;
    edge_t  *edge;

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

void
merge (edge_t *edge, int low, int mid, int high)
{

    edge_t *L;
    edge_t *R;
    int n1  = 0;
    int n2  = 0;
    int i   = 0;
    int j   = 0;
    int k   = 0;

    n1  = mid - low + 1;
    n2  = high - mid;

    L   = malloc (n1 * sizeof (edge_t));
    R   = malloc (n2 * sizeof (edge_t));

    for (i = 0; i < n1; i++) {
    
        L[i]    = edge[low + i];
    }

    for (j = 0; j < n2; j++) {
    
        R[j]    = edge[mid + 1 + j];
    }

    i   = 0;
    j   = 0;
    k   = low;
    while (i < n1 && j < n2) {
    
        if (L[i].wgh < R[j].wgh) {
        
            edge[k] = L[i];
            i++;
        } else {
        
            edge[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
    
        edge[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
    
        edge[k] = R[j];
        j++;
        k++;
    }

}

void
merge_sort (edge_t *edge, int low, int high)
{

    if (low < high) {
    
        int mid = 0;

        mid = low + ((high - low) / 2);

        merge_sort (edge, low, mid);
        merge_sort (edge, (mid + 1), high);

        merge (edge, low, mid, high);
    }

}

void
print_edges (edge_t *edge, int n)
{

    int i   = 0;

    if (!edge) {
    
        return;
    }

    printf ("SRC\t\tDST\t\tWEIGHT\n");
    for (i = 0; i < n; i++) {
    
        printf ("%d\t\t%d\t\t%d\n", edge[i].src, edge[i].dst, edge[i].wgh);
    }
    printf ("\n");

}

void
kruskal_mst (graph_t *g)
{

    subset_t *subset;
    edge_t *result;
    edge_t next_edge;
    int x   = 0;
    int y   = 0;
    int i   = 0;
    int j   = 0;
    int k   = 0;

    subset  = malloc (g->V * sizeof (subset_t));

    for (i = 0; i < g->V; i++) {
    
        subset[i].parent    = i;
        subset[i].rank      = 0;
    }

    result  = malloc (g->V * sizeof (edge_t));

    merge_sort (g->edge, 0, g->E);
    printf ("Sorted Edges based on weight: \n");
    print_edges (g->edge, g->E);

    i   = 0;
    j   = 0;
    k   = 0;
    while (i < (g->V - 1) && j < g->E) {
    
        next_edge   = g->edge[j];
        j++;

        x   = find (subset, next_edge.src);
        y   = find (subset, next_edge.dst);

        if (x != y) {
        
            result[k]   = next_edge;
            k++;
            union_set (subset, x, y);
        }
    }

    printf ("Following edges are included in Kruskal's MST:\n");
    print_edges (result, k);

    return;

}

int
main ()
{

    int V   = 0;
    int E   = 0;
    graph_t *g;

    V   = 4;
    E   = 5;

    g   = create_graph (V, E);
   
    /*
     * creating the below graph
     */
    /*
     *    10
     *  0-----1
     *  | \   |
     * 6|  \  |15
     *  |  5\ |
     *  |    \|  
     *  2-----3
     *    4
     */


    g->edge[0].src  = 0;
    g->edge[0].dst  = 1;
    g->edge[0].wgh  = 10;

    g->edge[1].src  = 0;
    g->edge[1].dst  = 2;
    g->edge[1].wgh  = 6;
    
    g->edge[2].src  = 0;
    g->edge[2].dst  = 3;
    g->edge[2].wgh  = 5;
    
    g->edge[3].src  = 1;
    g->edge[3].dst  = 3;
    g->edge[3].wgh  = 15;
    
    g->edge[4].src  = 2;
    g->edge[4].dst  = 3;
    g->edge[4].wgh  = 4;

    printf ("Unsorted edges:\n");
    print_edges (g->edge, 5);

    kruskal_mst (g);

    return 0;

}

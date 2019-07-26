#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

    int                 data;
    struct list_node_t_ *prev;
    struct list_node_t_ *next;

} list_node_t;

list_node_t *
create_node (int data)
{

    list_node_t *new_node = NULL;

    new_node = malloc (sizeof (list_node_t));

    if (!new_node) {
    
        printf ("Memory Allocation Failed!!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;

}

list_node_t *
push (list_node_t **head, int data)
{

    list_node_t *new_node = NULL;

    new_node = create_node (data);

    if (*head == NULL) {
    
        *head = new_node;
        return (*head);
    }

    if ((*head) != NULL) {
    
        new_node->next  = *head;
        (*head)->prev   = new_node;
        *head           = new_node;
    }

    return (*head);

}

list_node_t *
get_last (list_node_t *node)
{

    while (node && node->next) {
    
        node = node->next;
    }

    return node;

}

void
swap (int *a, int *b)
{

    int temp = 0;

    temp    = *a;
    *a      = *b;
    *b      = temp;

}

list_node_t *
partition (list_node_t *l, list_node_t *h)
{

    list_node_t *i   = NULL;
    list_node_t *j   = NULL;
    int x           = 0;

    x = h->data;

    i = l->prev;

    for (j = l; j != h; j = j->next) {
    
        if (j->data < x) {
        
            i = (i == NULL) ? l : i->next;
            swap (&(i->data), &(j->data));
        }
    }
    
    i = (i == NULL) ? l : i->next;
    swap (&(i->data), &(h->data));

    return i;

}

void
quick_sort_util (list_node_t *l, list_node_t *h)
{

    if ((h != NULL) && (l != h) && (l != h->next)) {
    
        list_node_t *p = NULL;

        p = partition (l, h);

        quick_sort_util (l, p->prev);
        quick_sort_util (p->next, h);
    }

}

void
quick_sort (list_node_t *head)
{

    list_node_t *end = NULL;

    end = get_last (head);

    quick_sort_util (head, end);

}

void
print_list (list_node_t *head)
{

    list_node_t *temp = NULL;

    temp = head;
    while (temp) {
    
        printf ("%d ", temp->data);
        temp = temp->next;
    }
    printf ("\n");

}

int
main ()
{

    list_node_t *head = NULL;

    head = push (&(head), 5);
    head = push (&(head), 2);
    head = push (&(head), 9);
    head = push (&(head), 1);
    head = push (&(head), 0);

    printf ("List before Sorting: ");
    print_list (head);

    quick_sort (head);

    printf ("List after  Sorting: ");
    print_list (head);

    return 0;

}

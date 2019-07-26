#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

    int                 data;
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

    new_node->data  = data;
    new_node->next  = NULL;

    return new_node;

}

list_node_t *
push (list_node_t **head, int data)
{

    list_node_t *new_node = NULL;

    new_node = create_node (data);

    new_node->next  = *head;
    *head           = new_node;

    return (*head);

}

void
sorted_insert (list_node_t **head, list_node_t *new_node)
{

    list_node_t *curr = NULL;

    if (((*head) == NULL) || 
        ((*head)->data) >= new_node->data) {
    
        new_node->next  = *head;
        *head           = new_node;
    } else {
    
        curr = *head;
        while ((curr->next != NULL) && (curr->next->data < new_node->data)) {
        
            curr = curr->next;
        }
        new_node->next  = curr->next;
        curr->next      = new_node;
    }

}

void
insertion_sort (list_node_t **head)
{

    list_node_t *sorted = NULL;
    list_node_t *curr   = NULL;
    list_node_t *next   = NULL;

    curr = *head;
    while (curr != NULL) {
    
        next = curr->next;

        sorted_insert (&sorted, curr);

        curr = next;
    }

    *head = sorted;

}

void
print_list (list_node_t *node)
{

    while (node != NULL) {
    
        printf ("%d ", node->data);
        node = node->next;
    }
    printf ("\n");

}

int
main ()
{

    list_node_t *head = NULL;

    head = push (&(head), 10);
    head = push (&(head), -10);
    head = push (&(head), 2);
    head = push (&(head), 0);
    head = push (&(head), 90);
    head = push (&(head), 23);
    head = push (&(head), -1);

    printf ("List before Sorting: ");
    print_list (head);

    insertion_sort (&head);

    printf ("List after  Sorting: ");
    print_list (head);

    return 0;

}

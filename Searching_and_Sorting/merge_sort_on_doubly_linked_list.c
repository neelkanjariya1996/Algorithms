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

    new_node->data  = data;
    new_node->prev  = NULL;
    new_node->next  = NULL;

    return new_node;

}

void
insert (list_node_t **head, int data)
{

    list_node_t *new_node = NULL;

    new_node = create_node (data);

    if (!(*head)) {
    
        *head = new_node;
        return;
    }

    new_node->next  = *head;
    (*head)->prev   = new_node;
    *head           = new_node;

    return;

}

list_node_t *
merge (list_node_t *first, list_node_t *second)
{

    if (!first) {
    
        return second;
    }

    if (!second) {
    
        return first;
    }

    if (first->data <= second->data) {
    
        first->next         = merge (first->next, second);
        first->next->prev   = first;
        first->prev         = NULL;
        return first;
    } else {
    
        second->next        = merge (first, second->next);
        second->next->prev  = second;
        second->prev        = NULL;
        return second;
    }

}

list_node_t *
split (list_node_t *head)
{

    list_node_t *fast = NULL;
    list_node_t *slow = NULL;
    list_node_t *temp = NULL;   

    fast = head;
    slow = head;
    while (fast->next && fast->next->next) {
    
        fast = fast->next->next;
        slow = slow->next;
    }

    temp        = slow->next;
    slow->next  = NULL;

    return temp;

}

list_node_t *
merge_sort (list_node_t *head)
{

    if (!(head) || !(head->next)) {
    
        return head;
    }

    list_node_t *second = NULL;

    second = split (head);

    head    = merge_sort (head);
    second  = merge_sort (second);

    return merge (head, second);

}

void
print_list (list_node_t *head)
{

    list_node_t *temp   = NULL;

    temp = head;
    printf ("Forward  Traversal: ");
    while (head) {
    
        printf ("%d ", head->data);
        temp = head;
        head = head->next;
    }
    printf ("\n");

    printf ("Backward Traversal: ");
    while (temp) {
    
        printf ("%d ", temp->data);
        temp = temp->prev;
    }
    printf ("\n");

}

int
main ()
{

    list_node_t *head = NULL;

    insert (&head, 5);
    insert (&head, 20);
    insert (&head, 4);
    insert (&head, 3);
    insert (&head, 30);
    insert (&head, 10);

    printf ("List before Sorting: \n");
    print_list (head);

    merge_sort (head);

    printf ("List after  Sorting: \n");
    print_list (head);

    return 0;

}

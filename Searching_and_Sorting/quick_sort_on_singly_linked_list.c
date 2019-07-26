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

    if ((*head) == NULL) {
    
        *head = new_node;
        return (*head);
    }

    new_node->next  = *head;
    *head           = new_node;

    return (*head);

}

list_node_t *
get_tail (list_node_t *head)
{

    list_node_t *curr = NULL;

    curr = head;
    while (curr != NULL && curr->next != NULL) {
    
        curr = curr->next;
    }

    return curr;

}

list_node_t *
partition (list_node_t *head, list_node_t *end,
           list_node_t **new_head, list_node_t **new_end)
{

    list_node_t *pivot  = NULL;
    list_node_t *prev   = NULL;
    list_node_t *curr   = NULL;
    list_node_t *tail   = NULL;

    pivot   = end;
    curr    = head;
    tail    = pivot;

    while (curr != pivot) {
    
        if (curr->data < pivot->data) {
        
            if (*(new_head) == NULL) {
            
                *new_head = curr;
            }

            prev = curr;
            curr = curr->next;

        } else {
        
            if (prev) {
            
                prev->next = curr->next;
            }

            list_node_t *temp = NULL;

            temp        = curr->next;
            curr->next  = NULL;
            tail->next  = curr;
            tail        = curr;
            curr        = temp;
        }

    }

    if ((*new_head) == NULL) {
    
        (*new_head) = pivot;
    }

    (*new_end) = tail;

    return pivot;

}

list_node_t *
quick_sort_util (list_node_t *head, list_node_t *end)
{

    if (!head || head == end) {
    
        return head;
    }

    list_node_t *new_head   = NULL;
    list_node_t *new_end    = NULL;
    list_node_t *pivot      = NULL;

    pivot = partition (head, end, &new_head, &new_end);

    if (pivot != new_head) {
    
        list_node_t *temp = NULL;
        
        temp = new_head;
        while (temp->next != pivot) {
        
            temp = temp->next;
        }
        temp->next = NULL;

        new_head = quick_sort_util (new_head, temp);

        temp        = get_tail (new_head);
        temp->next  = pivot;
    
    }

    pivot->next = quick_sort_util (pivot->next, new_end);

    return new_head;

}

void
quick_sort (list_node_t **head) 
{

    *head = quick_sort_util (*head, get_tail (*head));
    return;

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

    head = push (&head, 5);
    head = push (&head, 9);
    head = push (&head, 2);
    head = push (&head, 1);
    head = push (&head, 0);

    printf ("Unsorted List: ");
    print_list (head);

    quick_sort (&head);

    printf ("Sorted list:   ");
    print_list (head);

    return 0;

}

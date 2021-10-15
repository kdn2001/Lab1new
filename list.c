// list/list.c
// 
// Implementation for linked list.
//
// David Daniels
//davidcharlesdaniels@gmail.com

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
   // allocate a new node in a heap using `malloc()` and set its data
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    head->value = 0;
    head->next = NULL;
    list_t * new_list = NULL;
    new_list = (list_t *) malloc(sizeof(list_t));
    new_list->head = head;
    return new_list; 
}
void list_free(list_t *l) {}

void list_print(list_t *l) {
    node_t * current = l->head;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }

}
 int list_length(list_t *l) { 
    int count = 0;  // Initialize count
    node_t * current = l->head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("The length of the list is %d\n",count); 
    return count;
 }

 void list_add_to_back(list_t *l, elem value) {
  node_t * current = l->head;
  while (current->next != NULL) {
      current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;
}

void list_add_to_front(list_t *l, elem value) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}
// void list_add_at_index(list_t *l, elem value, int index) {}

elem list_remove_from_back(list_t *l) { 
    int retval = 0;
    
    /* if there is only one item in the list, remove it */
    if (l->head->next == NULL) {
        retval = l->head->value;
        free(l->head);
        printf("The removed value is %d\n",retval); 
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = l->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->value;
    free(current->next);
    current->next = NULL;
    printf("The removed value is %d\n",retval); 
    return retval; 
}

elem list_remove_from_front(list_t *l) {    
    int retval = -1;
    node_t * next_node = NULL;

    if (l->head == NULL) {
        return -1;
    }
    
    next_node = (l->head)->next;
    retval = (l->head)->value;
    free(l->head);
    l->head = next_node;
    printf("The removed value is %d\n",retval); 
    return retval;
}

elem list_remove_at_index(list_t *l, int index) { 
    int i = 0;
    int retval = -1;
    list_t * current =  l->head;
    list_t * temp_node = NULL;

    if (index == 0) {
        return pop(head);
    }

    for (i = 0; i < index-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->value;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

// bool list_is_in(list_t *l, elem value) { return false; }
// elem list_get_elem_at(list_t *l, int index) { return -1; }
// int list_get_index_of(list_t *l, elem value) { return -1; }

#include <stdio.h>

#include "list.h"

int main() {
  list_t* test = list_alloc();
  list_print(test);
  printf("Tests for linked list implementation\n");
  list_length(test);
  list_add_to_back(test, 2);
  list_add_to_front(test, 5);
  list_add_to_front(test, 8);
  list_add_to_front(test, 10);
  list_print(test);
  list_length(test);
  list_remove_from_back(test);
  list_print(test);
  list_length(test);
  list_remove_from_front(test);
  list_print(test);
  list_length(test);   
  return 0;
}

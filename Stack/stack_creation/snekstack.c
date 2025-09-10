#include "snekstack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
  stack_t *newstack = malloc(sizeof(size_t) * capacity);
  if(newstack == NULL){
    free(newstack);
    return NULL;  
  }
  newstack->count = 0;
  newstack->capacity = capacity;
  newstack->data = malloc(capacity * sizeof(void *));
  if(newstack->data == NULL){
    free(newstack);
    return NULL;
  }
  
  return newstack;
}

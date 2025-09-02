#include <stdlib.h>

#include "snekobject.h"

snek_object_t *new_snek_integer(int value) {
  snek_object_t *ptr = malloc(sizeof(snek_object_t));
  if(ptr == NULL){
    return NULL;
  }
  ptr->kind = INTEGER;
  ptr->data.v_int = value;
  return ptr;  
}

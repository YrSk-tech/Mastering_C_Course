#include <stdlib.h>
#include <string.h>

#include "snekobject.h"

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {

  if(a == NULL || b == NULL){
    return NULL;
  }
  switch(a->kind){
    case INTEGER:
      if(b->kind == INTEGER){
        int sum = a->data.v_int + b->data.v_int;
        return new_snek_integer(sum);
      }else if(b->kind == FLOAT){
        float sum = a->data.v_float + b->data.v_float;
        return new_snek_float(sum);
      }else{
        return NULL;
      }
    case FLOAT:
      if(b->kind == INTEGER){
        float sum = a->data.v_float + b->data.v_float;
        return new_snek_float(sum);
      }else if(b->kind == FLOAT){
        float sum = a->data.v_float + b->data.v_float;
        return new_snek_float(sum);
      }else{
        return NULL;
      }
    case STRING:
      if(b->kind != STRING){
      return NULL;
      } 
      size_t len = strlen(a->data.v_string);
      len += strlen(b->data.v_string);
      char *tmp_s = calloc(len+1, sizeof(char));
      strcat(tmp_s, a->data.v_string);
      strcat(tmp_s, b->data.v_string);
      snek_object_t *s_obj = new_snek_string(tmp_s);
      free(tmp_s);
    return s_obj;
    
    case VECTOR3:
    if(b->kind != VECTOR3){
      return NULL;
    } 
      snek_object_t *v_obj = new_snek_vector3(a->data.v_vector3.x, a->data.v_vector3.y, a->data.v_vector3.z);
      v_obj->data.v_vector3.x = snek_add(v_obj->data.v_vector3.x, b->data.v_vector3.x);
      v_obj->data.v_vector3.y = snek_add(v_obj->data.v_vector3.y, b->data.v_vector3.y);
      v_obj->data.v_vector3.z = snek_add(v_obj->data.v_vector3.z, b->data.v_vector3.z);
    return v_obj;
    
    case ARRAY:
      if(b->kind != ARRAY){
      return NULL;
      } 
      size_t length = a->data.v_array.size + b->data.v_array.size;
      snek_object_t *a_obj = new_snek_array(length);
      
      for(size_t index = 0; index < a->data.v_array.size; index++){
        snek_array_set(
        a_obj, index , 
        snek_array_get(a,index) 
        );
      }
      for(size_t index = 0; index < b->data.v_array.size; index++){
        
        snek_array_set(
        a_obj, a->data.v_array.size + index, 
        snek_array_get(b,index) 
        );
        
      }
      return a_obj;
    default:
    return NULL;
  }
}

// don't touch below this line

int snek_length(snek_object_t *obj) {
  if (obj == NULL) {
    return -1;
  }

  switch (obj->kind) {
  case INTEGER:
    return 1;
  case FLOAT:
    return 1;
  case STRING:
    return strlen(obj->data.v_string);
  case VECTOR3:
    return 3;
  case ARRAY:
    return obj->data.v_array.size;
  default:
    return -1;
  }
}

snek_object_t *new_snek_array(size_t size) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }

  obj->kind = ARRAY;
  obj->data.v_array = (snek_array_t){.size = size, .elements = elements};
  return obj;
}

bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value) {
  if (array == NULL || value == NULL) {
    return false;
  }

  if (array->kind != ARRAY) {
    return false;
  }

  if (index >= array->data.v_array.size) {
    return false;
  }

  // Set the value directly now (already checked size constraint)
  array->data.v_array.elements[index] = value;
  return true;
}

snek_object_t *snek_array_get(snek_object_t *array, size_t index) {
  if (array == NULL) {
    return NULL;
  }

  if (array->kind != ARRAY) {
    return NULL;
  }

  if (index >= array->data.v_array.size) {
    return NULL;
  }

  // Get the value directly now (already checked size constraint)
  return array->data.v_array.elements[index];
}

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }

  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = VECTOR3;
  obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};

  return obj;
}

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}

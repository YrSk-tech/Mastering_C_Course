#include "exercise.h"

void concat_strings(char *str1, const char *str2) {
  char null_terminator = '\0';
  int str1_index = 0;
  int str2_index = 0;
  while(str1[str1_index] != null_terminator){
    str1_index ++;
  }
  while(str2[str2_index] != null_terminator){
         str1[str1_index] = str2[str2_index];
         str1_index ++;
         str2_index ++;
  }
  str1[str1_index] = null_terminator;
}

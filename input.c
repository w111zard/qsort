#include <stdio.h>

#include "input.h"
#include "memory.h"

int input_getline(char *line, int size) {
  int len;
  int c;
  
  for (len = 0; (len < size - 1)
	 && ((c = getchar()) != EOF) && (c != '\n'); ++len)
    line[len] = c;

  if (c == '\n')
    line[len++] = '\n';

  line[len] = '\0';

  return len;
}

#include <stdio.h>

#include "memory.h"
#include "str.h"
#include "input.h"
#include "qsort.h"

enum {
  MAX_LINE_LEN = 100,
  MAX_LINES_COUNT = 10
};

int readlines(char *lines[], int lines_max_count) {
  char line[MAX_LINE_LEN];
  char *p;

  int len;
  int lines_count = 0;
  
  while ((len = input_getline(line, MAX_LINE_LEN)) > 0) {
    if ((lines_count >= lines_max_count)
	|| ((p = memory_allocate(len)) == NULL)) {
      return -1;
    }

    else {
      line[len - 1] = '\0';
      str_copy(line, p);
      lines[lines_count++] = p;
    }
  }

  return lines_count;
}

void writelines(char *lines[], int lines_count) {
  while (lines_count-- > 0)
    printf("%s\n", *lines++);
}

void sort_lines(char *lines[], int size) {
  qsort(lines, 0, size - 1);
}

int main(int argc, char **argv) {
  char *lines[MAX_LINES_COUNT];

  int lines_count = readlines(lines, MAX_LINES_COUNT);

  if (lines_count > 0) {
    sort_lines(lines, lines_count);
    writelines(lines, lines_count);
    return 0;
  }

  else {
    printf("Error: input is too big to sort\n");
    return 1;
  }
}

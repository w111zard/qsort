#include "memory.h"

static char memory[MEMORY_SIZE];
static char *memory_free_position = memory;

char *memory_allocate(int n) {
  if (memory + MEMORY_SIZE - memory_free_position >= n) {
    memory_free_position += n;
    return memory_free_position - n;
  }

  else {
    // there is no enough space in the memory
    return 0;
  }
}

void memory_free(char *p) {
  if ((p >= memory) && (p < memory + MEMORY_SIZE))
    memory_free_position = p;
}

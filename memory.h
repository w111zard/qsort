#ifndef __MEMORY_H__
#define __MEMORY_H__

enum {
  MEMORY_SIZE = 10000
};

//extern static int memory[MEMORY_SIZE];
//extern static int memery_free_position;

char *memory_allocate(int n);
void memory_free(char *p);

#endif /* #ifndef __MEMORY_H__ */

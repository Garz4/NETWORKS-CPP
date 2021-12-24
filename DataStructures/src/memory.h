#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdio.h>
#include <stdlib.h>

#define ALLOCATE(ptr, type) \
  ptr = (type *) malloc(sizeof(type)); \
  if (ptr == NULL) { \
    fprintf(stderr, "ERROR: Out of memory.\n"); \
    exit(1); \
  }

#define DELETE(ptr) free(ptr);

#endif // MEMORY_H_

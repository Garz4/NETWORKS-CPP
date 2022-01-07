#ifndef OUTPUTSTREAM_H_
#define OUTPUTSTREAM_H_

#include <stdio.h>
#include <stdlib.h>

#define EXIT(code) exit(code);

// To make it bold, e. g., red: "\033[01;91m"

#define STDERR_RED(...) \
  fprintf(stderr, "\033[91m"); \
  fprintf(stderr, __VA_ARGS__); \
  fprintf(stderr, "\033[0m");

#define STDERR_GREEN(...) \
  fprintf(stderr, "\033[92m"); \
  fprintf(stderr, __VA_ARGS__); \
  fprintf(stderr, "\033[0m");

#endif // OUTPUTSTREAM_H_

#pragma once
#include <sys/mman.h>
#define Begin(size)                                                            \
  {                                                                            \
    void *begin = mmap((void *)0x0000666000000000, size,                       \
                       PROT_READ | PROT_WRITE | PROT_EXEC,                     \
                       MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 0, 0);         \
    if (begin == (void *)-1)                                                       \
      exit(9);                                              \
    void *end = begin;                                                      \
    for (int i = 0; i < size; i++)                                             \
      ((char *)begin)[i] = 0xcc;

#define End(size)                                                              \
  munmap(begin, size);                                                         \
  }

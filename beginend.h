#pragma once
#define End                                                                    \
  free(begin);                                                                 \
  }
#define Begin(size)                                                            \
  {                                                                            \
    void *begin = malloc(size);                                                \
    void *anchor = begin;                                                      \
    for (int i = 0; i < size; i++)                                             \
      ((char *)begin)[i] = 0xcc;


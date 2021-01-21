#pragma once

#include "n.h"

typedef void (*pith_t)(int, void *, void *, void *);

#define NARGO(n) void n(pith_t o, void *b, void *e, void *r)
#define PITH(n) void n(int m, void *b, void *e, void *r)
#define PS(g, f)                                                               \
  static PITH(NNNN(g, o, f, _pith));                                           \
  static NARGO(NNN(g, o, f)) {                                                 \
    f(NNNN(g, o, f, _pith), b, e, (void *[]){o, r});                           \
  }                                                                            \
  static PITH(NNNN(g, o, f, _pith)) {                                          \
    pith_t o = ((pith_t *)r)[0];                                               \
    r = ((void **)r)[1];                                                       \
    if (m != 0)                                                                \
      return o(m, b, e, r);

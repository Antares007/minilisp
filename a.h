#pragma once
#define CC_(a, b) a##b
#define CC(a, b) CC_(a, b)
#define CCC(a, b, c) CC(CC(a, b), c)
#define CCCC(a, b, c, d) CC(CC(a, b), CC(c, d))
typedef void (*pith_t)(int, void *, void *, void *);
#define N(n)                                                                   \
  static void n(pith_t pith, void *begin,  void *anchor, void *ret)
#define Npith(n)                                                               \
  static void n(int errcode, void *begin, void *anchor, void *ret)

#define Ps(n, nara)                                                            \
  Npith(CC(n, _pith));                                                         \
  N(n) { nara(CC(n, _pith), begin, anchor, (void *[]){pith, ret}); }           \
  Npith(CC(n, _pith)) {                                                        \
    pith_t pith = ((void **)ret)[0];             \
    ret = ((void **)ret)[1];                                                   \
    if (errcode != 0)                                                          \
      return pith(errcode, begin, anchor, ret);
#define Nand(n, nara, narb)                                                    \
  Npith(CC(n, _pith2)) {                                       \
    pith_t pith = ((void **)ret)[0];             \
    if (errcode != 0)                                                          \
      pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
    else                                                                       \
      pith(0, ((void **)ret)[2], anchor, ((void **)ret)[1]);                   \
  }                                                                            \
  Npith(CC(n, _pith1) {                                       \
    pith_t pith = ((void **)ret)[0];             \
    if (errcode != 0)                                                          \
      pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
    else                                                                       \
      narb(CC(n, _pith2), begin, anchor, ret);                                 \
  }                                                                            \
  N(n) {                                     \
    nara(CC(n, _pith1), begin, anchor, (void *[]){pith, ret, begin});          \
  }
#define Nor(n, nara, narb)                                                     \
  Npith(CC(n, _pith2)) {                                       \
    pith_t pith = ((void **)ret)[0];             \
    pith(errcode, begin, anchor, ((void **)ret)[1]);                           \
  }                                                                            \
  Npith(CC(n, _pith1)) {                                       \
    pith_t pith = ((void **)ret)[0];             \
    if (errcode != 0)                                                          \
      narb(CC(n, _pith2), begin, anchor, ret);                                 \
    else                                                                       \
      pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
  }                                                                            \
  N(n) {                                     \
    nara(CC(n, _pith1), begin, anchor, (void *[]){pith, ret});                 \
  }
#define A(T, v) (*(T *)anchor = v, anchor += sizeof(T))
#define S(T, n)                                                                \
  T n = *(T *)begin;                                                           \
  begin += sizeof(T);

#define MB                                                                     \
  {                                                                            \
    void *oa = anchor;
#define ME                                                                     \
  pith(0, oa, anchor, ret);                                                    \
  anchor = oa;                                                                 \
  }
#define M(...) MB;(__VA_ARGS__);ME
#define L return pith(-1, begin, anchor, ret)

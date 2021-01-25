#pragma once
#define CC_(a, b) a##b
#define CC(a, b) CC_(a, b)
#define CCC(a, b, c) CC(CC(a, b), c)
#define CCCC(a, b, c, d) CC(CC(a, b), CC(c, d))

#define N(n)                                                                   \
  static void n(void (*pith)(int, void *, void *, void *), void *begin,        \
                void *anchor, void *ret)
#define NPith(n)                                                               \
  static void n(int errcode, void *begin, void *anchor, void *ret)
#define PS(n, nara)                                                            \
  NPith(CC(n, _pith));                                                         \
  N(n) { nara(CC(n, _pith), begin, anchor, (void *[]){pith, ret}); }           \
  NPith(CC(n, _pith)) {                                                        \
    void (*pith)(int, void *, void *, void *) = ((void **)ret)[0];             \
    ret = ((void **)ret)[1];                                                   \
    if (errcode != 0)                                                          \
      return pith(errcode, begin, anchor, ret);
#define NaN(n, nara, narb)                                                     \
  static void CC(n, _pith2)(int errcode, void *begin, void *anchor,            \
                            void *ret) {                                       \
    void (*pith)(int, void *, void *, void *) = ((void **)ret)[0];             \
    if (errcode != 0)                                                          \
      pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
    else                                                                       \
      pith(0, ((void **)ret)[2], anchor, ((void **)ret)[1]);                   \
  }                                                                            \
  static void CC(n, _pith1)(int errcode, void *begin, void *anchor,            \
                            void *ret) {                                       \
    void (*pith)(int, void *, void *, void *) = ((void **)ret)[0];             \
    if (errcode != 0)                                                          \
      pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
    else                                                                       \
      narb(CC(n, _pith2), begin, anchor, ret);                                 \
  }                                                                            \
  static void n(void (*pith)(int, void *, void *, void *), void *begin,        \
                void *anchor, void *ret) {                                     \
    nara(CC(n, _pith1), begin, anchor, (void *[]){pith, ret, begin});          \
  }
#define NoN(n, nara, narb)                                                     \
  static void CC(n, _pith2)(int errcode, void *begin, void *anchor,            \
                            void *ret) {                                       \
    void (*pith)(int, void *, void *, void *) = ((void **)ret)[0];             \
    pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
  }                                                                            \
  static void CC(n, _pith1)(int errcode, void *begin, void *anchor,            \
                            void *ret) {                                       \
    void (*pith)(int, void *, void *, void *) = ((void **)ret)[0];             \
    if (errcode != 0)                                                          \
      narb(CC(n, _pith2), begin, anchor, ret);                                 \
    else                                                                       \
      pith(errcode, begin, anchor, ((void **)ret)[1]);                         \
  }                                                                            \
  static void n(void (*pith)(int, void *, void *, void *), void *begin,        \
                void *anchor, void *ret) {                                     \
    nara(CC(n, _pith1), begin, anchor, (void *[]){pith, ret});          \
  }

#define B                                                                      \
  {                                                                            \
    void *oa = anchor
#define O                                                                      \
  pith(0, oa, anchor, ret);                                                    \
  anchor = oa;                                                                 \
  }
#define A(T, v) (*(T *)anchor = v, anchor += sizeof(T))
#define S(T, n)                                                                \
  T n = *(T *)begin;                                                           \
  begin += sizeof(T);

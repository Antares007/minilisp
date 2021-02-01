#pragma once
#define CC_(a, b) a##b
#define CC(a, b) CC_(a, b)
#define CCC(a, b, c) CC(CC(a, b), c)
#define CCCC(a, b, c, d) CC(CC(a, b), CC(c, d))
typedef void (*pith_t)(int, void *, void *, void *);
#define N(n) static void n(pith_t pith, void *begin, void *end, void *ret)
#define Npith(n)                                                               \
  static void n(int err, void *begin, void *end, void *ret)

#define Nps(ps, n, nara)                                                       \
  Npith(CC(n, _pith));                                                         \
  N(n) { nara(CC(n, _pith), begin, end, (void *[]){pith, ret}); }           \
  Npith(CC(n, _pith)) {                                                        \
    pith_t pith = ((void **)ret)[0];                                           \
    ret = ((void **)ret)[1];                                                   \
    if (err ps 0)                                                          \
      return pith(err, begin, end, ret);
#define Nandps(n, nara) Nps(!=, n, nara)
#define Norps(n, nara) Nps(==, n, nara)
#define NandBegin(n, nara) Nandps(n, nara) {
#define NorBegin(n, nara) Norps(n, nara) {
#define NEnd }
#define Ncontpith(ps, n, n2, nar)                                              \
  Npith(n) {                                                                   \
    pith_t pith = ((void **)ret)[0];                                           \
    if (err ps 0)                                                          \
      pith(err, begin, end, ((void **)ret)[1]);                         \
    else                                                                       \
      nar(n2, begin, end, ret);                                             \
  }
#define Nand(n, nara, narb)                                                    \
  Npith(CC(n, _pith2)) {                                                       \
    pith_t pith = ((void **)ret)[0];                                           \
    if (err != 0)                                                          \
      pith(err, begin, end, ((void **)ret)[1]);                         \
    else                                                                       \
      pith(0, ((void **)ret)[2], end, ((void **)ret)[1]);                   \
  }                                                                            \
  Ncontpith(!=, CC(n, _pith1), CC(n, _pith2), narb) N(n) {                     \
    nara(CC(n, _pith1), begin, end, (void *[]){pith, ret, begin});          \
  }
#define Nor(n, nara, narb)                                                     \
  Npith(CC(n, _pith2)) {                                                       \
    pith_t pith = ((void **)ret)[0];                                           \
    pith(err, begin, end, ((void **)ret)[1]);                           \
  }                                                                            \
  Ncontpith(==, CC(n, _pith1), CC(n, _pith2), narb);                           \
  N(n) { nara(CC(n, _pith1), begin, end, (void *[]){pith, ret}); }
#define A(T, v) (*(T *)end = v, end += sizeof(T))
#define S(T, n)                                                                \
  T n = *(T *)begin;                                                           \
  begin += sizeof(T);

#define MB                                                                     \
  {                                                                            \
    void *oa = end;
#define ME                                                                     \
  pith(0, oa, end, ret);                                                    \
  end = oa;                                                                 \
  }
#define o(...)                                                                 \
  MB;                                                                          \
  (__VA_ARGS__);                                                               \
  ME
#define Leturn return pith(-1, begin, end, ret)

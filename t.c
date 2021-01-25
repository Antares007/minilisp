#include "a.h"
#define Rws                                                                    \
  current == ' ' || current == '\n' || current == '\r' || current == '\t'
#define Rend current == -1
#define RendOerror current < 0
#define AP(T, v) (*(T *)begin = (T)current, begin += sizeof(T))
#define Range(a, b) (a <= current && current <= b)

#include <stdint.h>
typedef int8_t byte;
typedef int16_t word;
typedef int32_t doub;
typedef int64_t quad;
typedef void *star;
typedef uint8_t Byte;
typedef uint16_t Word;
typedef uint32_t Doub;
typedef uint64_t Quad;
typedef int (*fun)();
#include <stdio.h>
typedef int (*next_f)();
#define Lrror pith(-1, 0, 0, ret)

N(symbol) {
  S(unsigned char, current);
  S(next_f, next);

  while (Rws)
    current = next();
  if (Range('A', 'Z')) {
    AP(char, current);
    size_t len = 0;
    while ((current = next()) && (Range('A', 'Z') || Range('0', '9')))
      (AP(char, current), len++);
  } else
    Lrror;
}

NN(a, symbol) {
  S(unsigned char, current);
  S(next_f, next);
  B;
  A(char *, "hello world");
  O;
}
}
// static void read(void o(), char current, int next(), void *begin, void *end,
//                 void *ret) {
//  o(ret, 's', 'abcd');
//}
// typedef void (*n_t)();
// static void foreadpith(void *op, short type, int value) {
//  if (type == 'L')
//    ((n_t)op)(op, type, value);
//  else {
//  }
//}
// static void foread(void o(), char current, int next(), void *begin, void
// *end,
//                   void *ret) {
//  read((n_t)foreadpith, current, next, begin, end, o);
//}
//
// static void loop(void o(), void *begin, void *end) {}
////#include <stdio.h>
// static void p(void *o, void *begin, void *end) {
//  printf("%p %p\n", begin, end);
//  loop(o, begin += 1, end += 2);
//}
NPith(p) {}
int main() {
  // loop(p, 0, 0);

  aosymbol(p, 0, 0, 0);
  char *s = "obar";
  unsigned long int id =
      ((unsigned int)s[0] << 3 * 8) | ((unsigned int)s[1] << 2 * 8) |
      ((unsigned int)s[2] << 1 * 8) | ((unsigned int)s[3] << 0 * 8);
  unsigned long int id2 = 'haha';
  printf("%s\n", (char *)&id);
  printf("%s\n", (char *)&id2);
  return 0;
}

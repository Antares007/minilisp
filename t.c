#include "t.h"
#include "a.h"
#define R1of4(a, b, c, d)                                                      \
  (current == (unsigned char)a || current == (unsigned char)b ||               \
   current == (unsigned char)c || current == (unsigned char)d)
#define R0of4(a, b, c, d)                                                      \
  (current != (unsigned char)a && current != (unsigned char)b &&               \
   current != (unsigned char)c && current != (unsigned char)d)
#define Rand(a, b) (a <= current && current <= b)
#define Ror(a, b) (current < a || b < current)
#define Req(a) (current == a)
#define Rend current == -1
#define Rerror current < 0
#define Shift (current = getchar())
#define Shiftws                                                                \
  while (R1of4(' ', '\n', '\r', '\t'))                                         \
  Shift
#define AP(T, v) (*(T *)begin = (T)current, begin += sizeof(T))
#include <stdio.h>
static int current;

// Ab0
N(symbol) {
  Shiftws;
  if (Rand('A', 'Z') || Rand('a', 'z')) {
    unsigned long int symb = current & 0xff;
    char c = 1;
    while (Shift && (Rand('A', 'Z') || Rand('a', 'z') || Rand('0', '9'))) {
      if (c == 8)
        Leturn;
      symb = symb | ((current & 0xff) << 8 * c);
      c++;
    }
    O(A(unsigned long int, 'symb'), A(unsigned long int, symb));
  } else
    Leturn;
}
// ( sexp ... sexp )
Norps(sexp, symbol) {
  Shiftws;
  if (Req('(')) {
    Shift;
    Shiftws;
    if (Req(')')) {
    } else {
      O(A(unsigned long int, 'cons'), A(void *, sexp), A(void *, sexp));
    }
  } else
    Leturn;
}
NEnd;
Npith(eval) {
  S(unsigned long int, type);
  if (type == 'cons') {
    S(void *, head);
    S(void *, tail);
    printf("cons %p %p\n", head, tail);
  } else if (type == 'symb') {
    S(unsigned long int, symbol);
    printf("symb %s\n", (char *)&symbol);
  } else {
    printf("bug\n");
  }
}
#include "beginend.h"
//#include "hexdump.h"
#include <stdlib.h>
int main() {
  int err = 0;
  Begin(1024);
  Shift;
  sexp(eval, begin, anchor, &err);
  End;
  return err;
}

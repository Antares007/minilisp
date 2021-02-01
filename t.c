#include "t.h"
#include "n.h"
#include <sys/types.h>
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
    Quad symb = current & 0xff;
    byte c = 1;
    Shift;
    while (Rand('A', 'Z') || Rand('a', 'z') || Rand('0', '9')) {
      if (c == 8)
        Leturn;
      symb = symb | ((Quad)(current & 0xff) << (8 * c));
      c++;
      Shift;
    }
    o(A(Word, 0xbe48), // mov rsi,
      A(Quad, 'symb'), //
      A(Word, 0xba48), // mov rdx,
      A(Quad, symb),   //
      A(Word, 0xe7ff)  // jmp rdi
    );
  } else
    Leturn;
}

static void slist(pith_t, void *, void *, void *);
// ( sexp ... sexp )
Norps(sexp, symbol) {
  Shiftws;
  if (Req('(')) {
    Shift;
    Shiftws;
    if (Req(')'))
      Shift;
    else
      o(A(Quad, 'cons'), A(void *, sexp), A(void *, slist))
  } else
    Leturn;
}
NEnd;
Norps(slist, sexp) {
  Shiftws;
  if (Req(')'))
    Shift;
  else
    Leturn;
}
NEnd;
// S_ ::= S_ a / b
N(ws) {
  Shiftws;
  pith(0, begin, end, ret);
}
Nandps(aaa, ws) {
  if (Req('a')) {
    Shift;
    o(A(int, 1));
    aaa(pith, begin, end, ret);
  } else
    Leturn;
}
NEnd;

Nandps(S_, ws) {
  if (Req('b')) {
    o(A(int, 0));
    Shift;
    aaa(pith, begin, end, ret);
    // Shiftws;
    // while (Req('a')) {
    //  o(A(int, 1));
    //  Shift;
    //  Shiftws;
    //}
  } else
    Leturn;
}
NEnd;
// N(cons) {}
typedef void (*n_t)(pith_t, void *, void *, void *);
Npith(eval) {
  S(Quad, type);
  if (type == 'cons') {
    S(n_t, head);
    S(n_t, tail);
    printf("cons %p %p\n", head, tail);
    head(eval, end, end, ret);
    tail(eval, end, end, ret);
  } else if (type == 'symb') {
    S(Quad, symbol);
    printf("symb %s\n", (char *)&symbol);
  } else {
    printf("syntax error\n");
  }
}
#include "beginend.h"
#include "hexdump.h"
#include <stdlib.h>
void (*pith)() = hexdump;
void SS(pith_t pith, void *b, void *a, void *r) { S_(pith, b, a, r); }
int main() {
  int err = 0;
  Begin(4096);
  Shift;
  SS(hexdump, begin, end, &err);
  End(4096);
  if (err)
    printf("error\n");
  return err;
}

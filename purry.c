// RDI, RSI, RDX, RCX, R8, R9
#include "a.h"

N(narb) {
  O( //
      A(int, 1), A(int, 2), A(int, 3));
  O( //
      A(int, 4), A(int, 5), A(int, 6));
}
N(err) { L; }
Nor(ab, narb, err);

#include <stdio.h>
#include <stdlib.h>

Npith(p) {
  for (int i = 0; i < 9; i++) {
    S(int, v);
    printf("%d ", v);
  }
  printf("\n");
  *(int *)ret = 1;
}

int main() {
  int ret = 0;
  void *m = malloc(1024);
  for (int i = 0; i < 1024; i++)
    ((char *)m)[i] = 0xcc;
  ab(p, m, m, &ret);
  free(m);
  return ret;
}

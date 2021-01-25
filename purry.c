// RDI, RSI, RDX, RCX, R8, R9
#include "a.h"
N(nara) {
  //B;
  //A(int,42);
  //O;
  pith(-1,begin,anchor,ret);
}
N(narb) {
  B;
  A(int,43);
  O;
}

NoN(ab,nara,narb);
#include <stdio.h>
#include <stdlib.h>

NPith(p) {
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

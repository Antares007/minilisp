#include "n.h"
N(nar1) { 
  pith(-1,begin,end,ret);
  o(A(int, 1), A(int, 2));
}
N(nar2) { o(A(int, 3), A(int, 4)); }
N(nar3) { o(A(int, 5), A(int, 6)); }

Nor(aa, nar1, nar2);
Nand(aaa, nar3, aa);

#include "beginend.h"
#include "hexdump.h"
#include <stdio.h>
#include <stdlib.h>

void test(pith_t pith, void *begin, void *end, void *ret) {
  aaa(pith, begin, end, ret);
}

int main(int argc, char *argv[]) {
  int ret = 0;
  Begin(1024);
  test(hexdump, begin, end, &ret);
  End(1024);
  return ret;
}

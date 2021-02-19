#include "n.h"
N(nar1) {
  pith(-1, begin, end, ret);
  o(A(int, 1), A(int, 2));
}
N(nar2) { o(A(int, 3), A(int, 4)); }
N(nar3) { o(A(int, 5), A(int, 6)); }

Nor(aa, nar1, nar2);
Nand(aaa, nar3, aa);

void hexdump(int err, void *begin, void *end, void *ret);
void mem(pith_t pith, void *begin, void *end, void *ret);

void test(pith_t pith, void *begin, void *end, void *ret) {
  aaa(pith, begin, end, ret);
}
Nandps(mmm, mem) { //
  pith(err, begin, end, ret);
}
NEnd;
int main(int argc, char *argv[]) {
  int ret = 0;
  mmm(hexdump, 0, 0, &ret);
  return ret;
}

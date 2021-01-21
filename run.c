#include "a.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

static NARGO(start) {
  size_t size = 1 << 20;
  void *a =
      mmap((void *)0x0000666000000000, size, PROT_READ | PROT_WRITE | PROT_EXEC,
           MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 0, 0);
  if (a == (void *)-1)
    return o(-1, 0, 0, r);
  o(0, a, a + size, r);
  munmap(a, size);
}
void nil() {}
void tp(void *o, void *a, void *b) {
  if (b == nil)
    printf("%p %p %p\n", a, b, nil);
}

// mov rsi, h
// mov rdx, t
// jmp rdi
void writecell(void *a, void *h, void *t) {
  *(uint16_t *)(a + 0x00) = 0xbe48;
  *(uint64_t *)(a + 0x02) = (uint64_t)h;
  *(uint16_t *)(a + 0x0a) = 0xba48;
  *(uint64_t *)(a + 0x0c) = (uint64_t)t;
  *(uint16_t *)(a + 0x14) = 0xe7ff;
}

static PITH(pith) {
  writecell(b, tp, nil);
  for (int i = 0; i < 22; i++) {
    if (i % 10 == 0)
      printf("\n");
    printf("%02x", *(char *)(b + i) & 0xff);
  }
  void (*bark)(void o(void *, void *, void *)) = b;
  printf("\n");
  bark(tp);
}

int main(int argc, char *argv[]) {
  int r = 0;
  start(pith, 0, 0, &r);
  return 0;
}

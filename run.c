#include "a.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

NarGo(start) {
  size_t size = 1 << 20;
  void *a =
      mmap((void *)0x0000666000000000, size, PROT_READ | PROT_WRITE | PROT_EXEC,
           MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 0, 0);
  if (a == (void *)-1)
    return pith(-1, 0, 0, ret);
  pith(0, a, a + size, ret);
  munmap(a, size);
}
void nil() {}
void tp(void *o, void *a, void *b, char t) {
  printf("C %s %p %c\n", (char *)&a, b, t);
  if (b) {
    void (*bark)(void o(void *, void *, void *)) = b;
    bark(o);
  }
}

void writecell(void *a, void *h, void *t, char type) {
  // mov rsi, h
  *(uint16_t *)(a + 0x00) = 0xbe48;
  *(uint64_t *)(a + 0x02) = (uint64_t)h;
  // mov rdx, t
  *(uint16_t *)(a + 0x0a) = 0xba48;
  *(uint64_t *)(a + 0x0c) = (uint64_t)t;
  // mov cl, type
  *(uint8_t *)(a + 0x14) = 0xb1;
  *(uint8_t *)(a + 0x15) = type;
  // jmp rdi
  *(uint16_t *)(a + 0x16) = 0xe7ff;
}

 NarGoPith(pith) {
  for (int i = 0; 1; i++) {
    if (i < 2)
      writecell(begin + i * 0x18, (void *)'a' + i, begin + (i + 1) * 0x18, 'A' + i);
    else {
      writecell(begin + i * 0x18, (void *)'a' + i, 0, 'A' + i);
      break;
    }
  }

  for (int i = 0; i < 0x18 * 3; i++) {
    if (i % 0x18 == 0)
      printf("\n");
    printf("%02x", *(char *)(begin + i) & 0xff);
  }
  void (*bark)(void o(void *, void *, void *, char)) = begin;
  printf("\n");
  bark(tp);
}

typedef void (*nexp_t)(void o());
typedef void (*atom_t)(void o());
void *read() { return 0; }
void *eval(void *sexp) { return 0; }
void *print() { return 0; }
#include <stdlib.h>

void cstr(void o(), char c, int n()) {
  if (c != '"')
    o('L');
  else {
    static size_t size = 1024;
    static char *m = 0;
    if (m == 0)
      m = malloc(size);
    while ((c = n()) && c != '"') {
    }
    o('R', m);
  }
}

#define Range(a, b) (a <= current && current <= b)
#define Rws                                                                    \
  current == ' ' || current == '\n' || current == '\r' || current == '\t'

#define Rend current == -1
#define RendOerror current < 0
#define A(T, v) (*(T *)begin = (T)current, begin += sizeof(T))

void symbol(void o(), char current, int next(), void *begin, void *end,
          void *ret) {
  while (Rws)
    current = next();
  if (Range('A', 'Z')) {
    A(char, current);
    size_t len=0;
    while ((current = next()) && (Range('A', 'Z') || Range('0', '9'))) 
      (A(char, current),len++);
  } else
    o(ret, 'L');
}
void p(void *id, uint64_t m, char *b, void *e) {
  printf("%s %s\n", (char *)&m, b);
}
int main(int argc, char *argv[]) {
  if (EOF)
    printf("help %d", EOF);
  symbol(p, getchar(), getchar, 0, 0, 0);
  int r = 0;
  start(pith, 0, 0, &r);
  // ;
  // print(eval(read()));
  return 0;
}

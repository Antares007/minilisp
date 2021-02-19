#include "n.h"
#include <stdio.h>
#include <sys/mman.h>

void hexdump(int err, void *begin, void *end, void *ret) {
  char i = 0;
  if (err)
    printf("Leturn\n");
  for (; begin < end; begin = (char *)begin + 1) {
    if (i == 16)
      (printf("\n"), i = 0);
    if (i == 8)
      printf(" ");
    printf("%02x", *(char *)begin & 0xff);
    i++;
  }
  printf("\n");
  *(int *)ret = 1;
}
void mem(pith_t pith, void *begin, void *end, void *ret) {
  unsigned int size = 4096;
  begin = end =
      mmap((void *)0x0000666000000000, size, PROT_READ | PROT_WRITE | PROT_EXEC,
           MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 0, 0);
  if (begin == (void *)-1)
    return pith(-1, begin, end, ret);
  for (int i = 0; i < size; i++)
    ((char *)begin)[i] = 0xcc;
  pith(0, begin, end, ret);
  munmap(begin, size);
}

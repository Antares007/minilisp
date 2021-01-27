#pragma once
#include "a.h"
#include <stdio.h>
Npith(hexdump) {
  char i = 0;
  if (errcode)
    printf("Leturn\n");
  for (; begin < anchor; begin = (char *)begin + 1) {
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

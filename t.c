#include <stdio.h>

void p();
void t();
void z();

void bark(int s, void (*o)(int)) {z(); o(s); }

void pith(int i) {
  if (i < 10){
    p();
    bark(i + 1, pith);
  }
  else
    t();
}

int main() {
  bark(0, pith);
  return 9;
}



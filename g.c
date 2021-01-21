/*
<LETTER>        ::= A|B|C|...|Z
<number>        ::= 0|1|2|...|9
<atomic_symbol> ::= <LETTER><atom_part>
<atom_part>     ::= <empty>
                  | <LETTER><atom_part>
                  | <number><atom_part>
<S_expression>  ::= <atomic_symbol>
                  | (<S_expression>.<S_expression>)
                  | (<S_expression>...<S_expression>)
*/

//char *letter(char *b, char *e) { //
//  return b + (b < e && 'A' < *b && *b <= 'Z');
//}
//char *number(char *b, char *e) { //
//  return b + (b < e && '0' < *b && *b <= '9');
//}
//typedef void (*gp_t)(int,void*,void*);
//
//void S0(gp_t o);
//void S3(gp_t o) { o('T', "b", 0); }
//void S2(gp_t o) { o('T', "a", 0); }
//void S1(gp_t o) { o('A', S0, S2); }
//void S0(gp_t o) { o('C', S1, S3); }

int main() {
  //
  char *b = "A";
  return 'A' <= *(char *)b && *(char *)b <= 'Z';
}

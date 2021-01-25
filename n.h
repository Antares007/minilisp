#pragma once

#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define NNN(a, b, c) NN(NN(a, b), c)
#define NNNN(a, b, c, d) NN(NN(a, b), NN(c, d))
#define NNNNN(a, b, c, d, e) NN(NN(a, b), NNN(c, d, e))
#define NNNNNN(a, b, c, d, e, f) NN(NN(a, b), NNNN(c, d, e, f))

//#ifndef SINGLEQUOTE
//#define SINGLEQUOTE '
//#endif
//#define CHARIFY(x) NNN(SINGLEQUOTE, x, SINGLEQUOTE)

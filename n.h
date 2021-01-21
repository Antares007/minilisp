#pragma once

#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define NNN(a, b, c) NN(NN(a, b), c)
#define NNNN(a, b, c, d) NN(NN(a, b), NN(c, d))


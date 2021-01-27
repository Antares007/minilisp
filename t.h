#pragma once
#include<stdint.h>
typedef int8_t byte;
typedef int16_t word;
typedef int32_t doub;
typedef int64_t quad;
typedef uint8_t Byte;
typedef uint16_t Word;
typedef uint32_t Doub;
typedef uint64_t Quad;

/*
  byte |7654 3210|
       |0101 1010|
       0x59
  word |7654 3210|7654 3210|
       |0101 1011|0101 1011|
       0xFFFF
  doub |7654 3210|7654 3210|7654 3210|7654 3210|
       |0101 1011|0101 1011|0101 1011|0101 1011|
       0xFFFFFFFF
  quad |7654 3210|7654 3210|7654 3210|7654 3210|7654 3210|7654 3210|7654 3210|7654 3210|
       |0101 1011|0101 1011|0101 1011|0101 1011|0101 1011|0101 1011|0101 1011|0101 1011|
       0xFFFFFFFFFFFFFFFF
*/

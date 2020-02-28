#ifndef DECODE_H_INCLUDED
#define DECODE_H_INCLUDED

#include "includes.h"

string decode(string inputPath, string outputPath);
void unpack_byte(byte b, bool *bits);

extern int n;
extern string  letters;
extern int   *wordLengths;
extern bool  **codeMatrix;

#endif // DECODE_H_INCLUDED

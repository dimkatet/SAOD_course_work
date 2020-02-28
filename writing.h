#ifndef WRITING_H_INCLUDED
#define WRITING_H_INCLUDED

#include "includes.h"
#include "decode.h"

void write(string input, string output);
void printLenght();
byte pack_byte(bool bits[8]);

extern int n;
extern string  letters;
extern vector <float> probability;
extern int   *wordLengths;
extern bool  **codeMatrix;

#endif // WRITING_H_INCLUDED

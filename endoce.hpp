#ifndef ENDOCE_HPP_INCLUDED
#define ENDOCE_HPP_INCLUDED

#include "includes.h"
#include "Sort.hpp"

void encode(string input, string output);
int readData(string _path);
void printMatrix();
void shannon();
void write(string input, string output);
byte pack_byte(bool bits[8]);
void printLenght();

extern int n;
extern string  letters;
extern vector <float> probability;
extern float          *cumulProbability;;
extern int   *wordLengths;
extern bool  **codeMatrix;
#endif // ENDOCE_HPP_INCLUDED

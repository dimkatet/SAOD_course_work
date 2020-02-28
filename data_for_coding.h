#ifndef DATA_FOR_CODING_H_INCLUDED
#define DATA_FOR_CODING_H_INCLUDED

#include "includes.h"
#include "Sort.hpp"

using namespace std;

int readData(string _path);
void printMatrix();

extern int n;
extern string  letters;
extern vector <float> probability;
extern float          *cumulProbability;;
extern int   *wordLengths;
extern bool  **codeMatrix;

#endif // DATA_FOR_CODING_H_INCLUDED

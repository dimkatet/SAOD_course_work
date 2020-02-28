#ifndef READ_FILE_HPP_INCLUDED
#define READ_FILE_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;
struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;
};

struct node
{
    record data;
    node* next;
};

void readFile(node *s);
int sizeOfDataBase(node *s);

#endif // READ_FILE_HPP_INCLUDED

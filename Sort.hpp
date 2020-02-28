#ifndef SORT_HPP_INCLUDED
#define SORT_HPP_INCLUDED

#include "includes.h"
#include "ReadFile.hpp"
struct body {
    node *head;
    node *tail;
};
void MergeSort(node* &S, int n);
bool diff(record a, record b);

void InsertSort(string &str, int n);
void InsertSort(std::vector<float> &p, string &str, int n);
void InsertSort(string &str, std::vector<float> &p, int n);

#endif // SORT_HPP_INCLUDED

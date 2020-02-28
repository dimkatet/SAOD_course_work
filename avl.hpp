#ifndef AVL_H
#define AVL_H

#include "ReadFile.hpp"
#include "IndexArray.hpp"
#include "Print.hpp"
#include <iostream>

using namespace std;

struct avlnode
{
    avlnode* left;
    avlnode* right;
    int balance;
    node* list;
    avlnode(record _data)
    {
        list = new node;
        list->data = _data;
        left = NULL;
        right = NULL;
        balance = 0;
	};
    void addNode(record _data)
    {
        node *temp = list;
        while (temp->next!=NULL)
            temp = temp ->next;
        temp->next = new node;
        temp = temp->next;
        temp->data = _data;
        temp->next = NULL;
    };
    void printList()
    {
        node *temp = list;
        while(temp!=NULL)
        {
            cout<< temp->data.author << "  " << temp->data.publisher << "  "
            << temp->data.title << "  " << temp->data.year << "  " << temp->data.num_of_page << endl;
            temp = temp->next;
        }
    };
};
//Adding
avlnode* buildTree(node *data, int n);
avlnode *searchNode(avlnode *root, char* key);
void printTree(avlnode *root);
void LLRotation(avlnode*& p);
void LRRotation(avlnode*& p);
void RRRotation(avlnode*& p);
void RLRotation(avlnode*& p);
void addNode(avlnode*& p, record* _item,  bool* _growth);

//Deleting
void BLDelete(avlnode*& p, bool* _decreasing);
void BRDelete(avlnode*& p, bool* _decreasing);
void RR1Rotation(avlnode*& p, bool* _decreasing);
void LL1Rotation(avlnode*& p, bool* _decreasing);
void deleteNode(avlnode*& p, record _item, bool* _decreasing);
void delNode(avlnode*& p, avlnode*& q, bool* _decreasing);
#endif // AVL_H

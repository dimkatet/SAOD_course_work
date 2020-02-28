#include "avl.hpp"
#include <iostream>
//Adding

void LLRotation(avlnode*& p)
{
    avlnode* q = p->left;
    q->balance = 0;
    p->balance = 0;
    p->left = q->right;
    q->right = p;
    p = q;
}

void LRRotation(avlnode*& p)
{
    avlnode* q = p->left;
    avlnode* r = q->right;
    if(r->balance < 0)
        p->balance = 1;
    else
        p->balance = 0;
    if(r->balance > 0)
        q->balance = -1;
    else
        q->balance = 0;
    r->balance = 0;
    p->left = r->right;
    q->right = r->left;
    r->left = q;
    r->right = p;
    p = r;
}

void RRRotation(avlnode*& p)
{
    avlnode* q = p->right;
    q->balance = 0;
    p->balance = 0;
    p->right = q->left;
    q->left = p;
    p = q;
}

void RLRotation(avlnode*& p)
{
    avlnode* q = p->right;
    avlnode* r = q->left;
    if(r->balance > 0)
        p->balance = -1;
    else
        p->balance = 0;
    if(r->balance < 0)
        q->balance = 1;
    else
        q->balance = 0;
    r->balance = 0;
    p->right = r->left;
    q->left = r->right;
    r->left = p;
    r->right = q;
    p = r;
}

void addNode(avlnode*& p, record* _item, bool* _growth)
{
    if(p == NULL)
    {
        p = new avlnode(*_item);
        *_growth = true;
    }
    else
    {
        if(searchDiff(p->list->data.title, _item->title)>0)
        {
            addNode(p->left, _item, _growth);
            if(*_growth == true)
            {
                if(p->balance > 0)
                {
                    p->balance = 0;
                    *_growth = false;
                }
                else
                {
                    if(p->balance == 0)
                        {
                            p->balance = -1;
                            *_growth = true;
                        }
                    else
                    {
                        if(p->left->balance < 0)
                        {
                            LLRotation(p);
                            *_growth = false;
                        }
                        else
                        {
                            LRRotation(p);
                            *_growth = false;
                        }
                    }
                }
            }
        }
        else if(searchDiff(p->list->data.title, _item->title)<0)
        {
            addNode(p->right, _item, _growth);
            if(*_growth == true)
            {
                if(p->balance < 0)
                {
                    p->balance = 0;
                    *_growth = false;
                }
                else if(p->balance == 0)
                    {
                        p->balance = 1;
                        *_growth = true;
                    }
                else if(p->right->balance > 0)
                {
                    RRRotation(p);
                    *_growth = false;
                }
                else
                {
                    RLRotation(p);
                    *_growth = false;
                }
            }
        }
        else if(searchDiff(p->list->data.title, _item->title)==0)
        {
            p->addNode(*_item);
        }
    }
}

void RR1Rotation(avlnode*& p, bool* _decreasing)
{
    avlnode *q = p->right;
    if(q->balance == 0)
    {
        p->balance = 1;
        q->balance = -1;
        *_decreasing = false;
    } else
    {
        p->balance = 0;
        q->balance = 0;
    }
    p->right = q->left;
    q->left = p;
    p = q;
}

void LL1Rotation(avlnode*& p, bool* _decreasing)
{
    avlnode *q = p->left;
    if(q->balance == 0)
    {
        p->balance = -1;
        q->balance = 1;
        *_decreasing = false;
    } else
    {
        p->balance = 0;
        q->balance = 0;
    }
    p->left = q->right;
    q->right = p;
    p = q;
}

avlnode* buildTree(node *data, int n)
{
    avlnode* head;
    head = NULL;
    record **indexArray = new record* [n];
    fillIndexArray(indexArray,data);
    bool growth;
    for(int i = 0; i < n; i++)
    {
        addNode(head, indexArray[i], &growth);
        //cout << i << endl;
    }
    return head;
}

void printTree(avlnode *root)
{
    avlnode *temp = root;
    if(root != NULL)
    {
        printTree(temp->left);
        printRec(temp->list);
        printTree(temp->right);
    }

}

avlnode *searchNode(avlnode *root, char* key)
{
    if(root==NULL)
    {
        cout << "Not found." << endl;
        return NULL;
    }
    if(searchDiff(root->list->data.title,key)==0)
    {
        cout << "Found: " << endl;
        printRec(root->list);
        return root;
    }
    else if(searchDiff(root->list->data.title,key) > 0)
    {
        searchNode(root->left,key);
    }
    else if(searchDiff(root->list->data.title,key) < 0)
    {
        searchNode(root->right,key);
    }
    return NULL;
}


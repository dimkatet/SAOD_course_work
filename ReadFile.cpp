#include "ReadFile.hpp"

void readFile(node *s)
{
    FILE *file;
    int i = 0, num = 4000;
    node *temp = s, *pred = temp;
    record dataArray[num];
    record *tempRec;
    file=fopen("testBase1.dat","rb");
    fread(dataArray,sizeof(record),num,file);
    while(i < num)
    {
        temp->data = dataArray[i];
        pred = temp;
        temp->next = new node;
        temp = temp->next;
        i++;
    }
    pred->next = NULL;
    delete(temp);
}

int sizeOfDataBase(node *s)
{
    node *temp = s;
    int i = 0;
    while (temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

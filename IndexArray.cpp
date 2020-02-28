#include "IndexArray.hpp"
#include <iostream>
void fillIndexArray(record **indexArray, node *baseHead)
{
    int i = 0;
    int n = sizeOfDataBase(baseHead);
    node* temp = baseHead;
    while(i < n)
    {
        indexArray[i] = &(temp->data);
        temp = temp->next;
        i++;
    }
}

node* binarySearch(record **indexArray,int dataSize, char *key)
{
    int left = 0, right = dataSize - 1, median = 0;
    bool isFound = false;
    node* foundKeysHead, *foundKeysTemp;
    foundKeysHead = foundKeysTemp = new node;
	while(left <= right)
	{
		median =(left + right)/2;
		if(!searchDiff(indexArray[median]->publisher, key))
		{
		    isFound = true;
			break;
		}
		else if(searchDiff(indexArray[median]->publisher, key)<0)
                left = median + 1;
            else
                right = median - 1;
	}
	int next = median - 1;
	while(next>=0)
	{
        if(searchDiff(indexArray[next]->publisher,key))
        {
            next--;
            break;
        }
        next--;
	}
	left = next + 1;
	right = median;
	next =  median + 1;
	while(next<dataSize)
	{
        if(searchDiff(indexArray[next]->publisher,key))
        {
            break;
        }
        right = next;
        next++;
	}
	if(isFound)
    {
        for(left;left<=right;left++)
        {
            foundKeysTemp->data = *indexArray[left];
            foundKeysTemp->next = new node;
            if(left!=right)
                 foundKeysTemp = foundKeysTemp->next;
            else foundKeysTemp->next = NULL;
        }
    }
    else foundKeysHead = NULL;
	return foundKeysHead;
}


int searchDiff(char* data, char *key)
{
    int diff = 0;
    for(int i = 0; i < 3; i++)
    {
        diff += data[i] - key[i];
        if(diff) break;
    }
    return diff;
}

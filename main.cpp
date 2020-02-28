#define byte_size 8

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

typedef unsigned char byte;

int main()
{
    node *dataBase = new node;
    node *sortDataBase = new node;
    node *searhNodes;
    avlnode* avlRoot;
    readFile(dataBase);
    readFile(sortDataBase);
    record **indexArray = new record* [sizeOfDataBase(dataBase)];
    string inputStr, outputStr, text;
    char *key = new char[3];
    char trash[100];
    char ch = 0;
    int mode = 0;
    bool isSearch = false;

    while(1)
    {
        mode = 0;
        ch = 0;
        cout <<  "Select: " << endl << "1. Print data" << endl << "2. Sort and search" << endl << "3. Build tree" << endl
        << "4. Data coding" << endl << "5. Data decoding" << endl << "0. Exit" << endl;
        cin >> mode;
        system("CLS");
        switch(mode)
        {
            case 0: return 0;
            case 1:
                printRec(dataBase);
                system("CLS");
                break;
            case 2:
                MergeSort(sortDataBase,sizeOfDataBase(sortDataBase));
                fillIndexArray(indexArray,sortDataBase);
                printArray(indexArray,sizeOfDataBase(sortDataBase));
                system("CLS");
                cout << "Do you want to search node? y/n" << endl;
                cin >> ch;
                system("CLS");
                if(ch!='n')
                {
                    cout << "Enter key for searching in index array: ";
                    cin >> key;
                    system("CLS");
                    searhNodes = binarySearch(indexArray,sizeOfDataBase(sortDataBase),key);
                    printRec(searhNodes);
                    system("CLS");
                    isSearch = true;
                }
                else isSearch = false;
                break;
            case 3:
                if(!isSearch)
                {
                    cout << "Error. First find data" << endl;
                    getch();
                    system("CLS");
                    break;
                }
                avlRoot = buildTree(searhNodes, sizeOfDataBase(searhNodes));
                printTree(avlRoot);
                system("CLS");
                cout << "Do you want to search node? y/n" << endl;
                cin >> ch;
                system("CLS");
                if(ch!='n')
                {
                    cout << "Enter key for searching in binary tree: ";
                    gets(trash);
                    gets(key);
                    system("CLS");
                    searchNode(avlRoot,key);
                }
                break;
            case 4:
                cout << "Enter input path: " << endl;
                cin >> inputStr;
                system("CLS");
                cout << "Enter output path: " << endl;
                cin >> outputStr;
                encode(inputStr,outputStr);
                cout << "Do you want to see code matrix? y/n" << endl;
                cin >> ch;
                system("CLS");
                if(ch!='n')
                {
                    printMatrix();
                    getch();
                    system("CLS");
                }
                break;
            case 5:
                cout << "Enter input path: " << endl;
                cin >> inputStr;
                system("CLS");
                shannon();
                cout << "Enter output path: " << endl;
                cin >> outputStr;
                text = decode(inputStr,outputStr);
                cout << "Do you want to see decode text? y/n" << endl;
                cin >> ch;
                system("CLS");
                if(ch!='n')
                    cout << text << endl;
                break;
            default:
                cout << "Invalid command" << endl;
                getch();
                system("CLS");
                break;

        }
    }
}


using namespace std;
int n;
string  letters;
vector <float> probability;
float          *cumulProbability;
int   *wordLengths;
bool  **codeMatrix;



#include "data_for_coding.h"

int readData(string _path)
{
    ifstream file(_path);
    if(!file) return 404;
    char tempChar;
    string str((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
    //cout << str << endl << str.size() << endl;
    //system("PAUSE");
    sort(str.begin(),str.end());
    tempChar = str[0];
    for(unsigned int i = 1, num = 1; i < str.size();i++)
    {
        if(tempChar != str[i])
        {
            letters.push_back(tempChar);
            probability.push_back(num/(float)str.size());
            tempChar = str[i];
            num = 1;
            if(i == str.size() - 1)
            {
                letters.push_back(tempChar);
                probability.push_back(num/(float)str.size());
            }
        }
        else
        {
            num++;
            if(i == str.size() - 1)
            {
                letters.push_back(tempChar);
                probability.push_back(num/(float)str.size());
            }
        }
    }
    InsertSort(probability,letters,probability.size());
    n = letters.size();
    wordLengths = new int [n];
    cumulProbability = new float [n];
    codeMatrix = new bool* [n];
    for(int i = 0; i < n; i++)
    {
        codeMatrix[i] = new bool [n];
        for(int j = 0; j < n; j++)
                codeMatrix[i][j] = 0;
        wordLengths[i] = cumulProbability[i] = 0;
    }
    return 0;
}

void printMatrix()
{
    cout << "symbol" << "  probability" << "  lengths" <<  "     code word" << endl;
    for(int i = 0; i < n; i++)
    {
        printf("  %c    %10f  %7d      ",letters[i],probability[i],wordLengths[i]);
        for(int j = 0; j < wordLengths[i]; j++)
            printf("%d  ",codeMatrix[i][j]);
        cout << endl;
    }
}

#include "endoce.hpp"

void encode(string input, string output)
{
    readData(input);
    shannon();
    write(input, output);
    printLenght();
}


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

void shannon()
{
    bool temp = 0;
    cumulProbability[0] = 0;
    wordLengths[0] = - log2(probability[0]) + 0.9999999999f;
    for(int i = 1; i < n; i++)
    {
        cumulProbability[i] = cumulProbability[i - 1] + probability[i - 1];
        wordLengths[i] = - log2(probability[i]) + 0.9999999999f;
    }
    //for(int i = 0; i < n; i++)
    //    cout << wordLengths[i] << "    " << cumulProbability[i] << endl;
    for(int i = 0; i < n; i++)
    {
        codeMatrix[i] = new bool [wordLengths[i]];
        for(int j = 0; j < wordLengths[i]; j++)
        {
            //cout << i << ":i   j:" << j << endl;
            cumulProbability[i] *= 2;
            if (cumulProbability[i] >= 1) temp = 1;
            else temp = 0;
            codeMatrix[i][j] = temp;
            if(cumulProbability[i]>1)
            {
                cumulProbability[i] -= 1;
            }
        }
    }
}

void write(string input, string output)
{
    ifstream inputFile(input);
    ofstream outputFile(output,ios::binary|ios::out);
    string str((std::istreambuf_iterator<char>(inputFile)),
               std::istreambuf_iterator<char>());
    byte bytes;
    bool bits[byte_size]= {0};
    int alphSize = letters.size();
    int strSize = str.size();
    outputFile.write((char*)&strSize, sizeof(strSize));
    outputFile.write((char*)&alphSize, sizeof(char));
    for(int i = 0; i < alphSize; i++)
        outputFile.write((char*)&letters[i], sizeof(char));
    for(int i = 0; i < alphSize; i++)
        outputFile.write((char*)&wordLengths[i], sizeof(char));
    for(int i = 0, b = byte_size - 1; i < alphSize; i++)
    {
        for(int y = 0; y < wordLengths[i]; y++)
        {
            bits[b] = codeMatrix[i][y];
            b--;
            if(b<0||((i == alphSize - 1) && (y == wordLengths[i] - 1)))
            {
                bytes = pack_byte(bits);
                for(int j = 0; j < byte_size; j++)
                    bits[j] = 0;
            b = byte_size - 1;
            outputFile.write((char*)&bytes,sizeof(byte));
            bytes = pack_byte(bits);
            }
        }
    }

    for(int i = 0, j = 0, b = byte_size - 1; i < str.size(); i++)
    {
        j = 0;
        for(j = 0; j < n; j++)
            if(str[i]==letters[j])
                break;
        for(int y = 0; y < wordLengths[j]; y++)
        {
            bits[b] = codeMatrix[j][y];
            b--;
            if(b<0||((i == str.size()-1) && (y == wordLengths[j] - 1)))
            {
                bytes = pack_byte(bits);
                for(int q = byte_size - 1; q >= 0; q--)
                {
                    bits[q] = 0;
                }
                b = byte_size - 1;
                outputFile.write((char*)&bytes,sizeof(byte));
                bytes = pack_byte(bits);
            }
        }
    }
}

void printLenght()
{
    float length = 0.f, entropy = 0.f;
    for(int i = 0; i < n; i++)
    {
        length+= wordLengths[i] * probability[i];
        entropy += probability[i] * log2(probability[i]);
    }
    entropy *= -1;
    cout << "length: " << length << endl << "entropy: " << entropy << endl;
}

byte pack_byte(bool bits[8])
{
    byte result(0);
    for(unsigned i(8); i--;)
    {
        result <<= 1;
        result |= byte(bits[i]);
    }
    return result;
}

#include "writing.h"

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



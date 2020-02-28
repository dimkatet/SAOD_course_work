#include "decode.h"

string decode(string inputPath, string outputPath)
{
    ifstream inputFile(inputPath, ios::binary|ios::in);
    bool bits[byte_size] = {0};
    char c;
    unsigned int strSize;
    inputFile.read((char *)&strSize, sizeof(strSize));
    inputFile.read(&c, sizeof(c));
    int alphSize = (unsigned char)c;
    n = alphSize;
    letters.clear();
    letters.reserve(alphSize);
    for(int i = 0; i < alphSize; i++)
    {
        char temp;
        inputFile.read(&temp, sizeof(temp));
        letters.push_back(temp);
    }
    wordLengths = new int[alphSize];
    for(int i = 0; i < alphSize; i++)
    {
        char temp;
        inputFile.read(&temp, sizeof(temp));
        wordLengths[i] = temp;
    }
    codeMatrix = new bool* [alphSize];
    int ib = byte_size - 1;
    //char c;
    for(int i = 0; i < alphSize; i++)
    {
        codeMatrix[i] = new bool[alphSize];
        for(int j = 0; j < alphSize; j++)
            codeMatrix[i][j] = 0;
        for(int j = 0; j < wordLengths[i]; j++)
        {
            if(ib == byte_size - 1)
            {
                inputFile.read((char*)&c, sizeof(char));
            }
            bitset<8> bs(c);
            //codeMatrix[i][j] = ((temp & 0x08) != 0);
            //temp = temp << 1;
            codeMatrix[i][j] = bs[ib];
            ib--;
            if(ib == -1)
                ib = byte_size - 1;
        }
    }
    cout<<"Done reading tables. Alphabet size: " << n << endl;
    string text((std::istreambuf_iterator<char>(inputFile)),
                 std::istreambuf_iterator<char>());
    cout<<"Put file into string. Size: " << text.size() << endl;
    string decodeText;
    bool allBits[byte_size*text.size()] = {0};
    byte b;
    for(int i = 0, temp = 0; i < text.size(); i++, temp+=byte_size)
    {
        b = text[i];
        unpack_byte(b,bits);
        for(int y = temp, j = byte_size - 1; y < temp+byte_size; y++, j--)
            allBits[y] = bits[j];
    }
    cout<<"Done reading bits. " << text.size() << endl;
    for(unsigned int i = 0; i < byte_size*text.size();i)
    {
        for(unsigned int y = 0, num = 0; y < n; y++)
        {
            num = 0;
            for(unsigned int j = 0; j < wordLengths[y]; j++)
            {
                if(allBits[j+i] == codeMatrix[y][j])
                    num++;
            }
            if(num==wordLengths[y])
                {
                i += wordLengths[y];
                decodeText.push_back(letters[y]);
                if (decodeText.size() == strSize)
                    {
                        i = byte_size*text.size();
                        y = n;
                    }
                break;
                }
            else if(y==n-1) return decodeText;
        }
    }
    cout<<"Done. Decoded text size: " << decodeText.size() << '/' << strSize << endl;
    fstream outputFile(outputPath, ios::binary|ios::out);
    cout<<"Opened outfile." << endl;
    outputFile << decodeText;
    cout<<"Done outputting text." << endl;
    outputFile.close();
    cout<<"Closed output." << endl;
    return decodeText;
}


void unpack_byte(byte b, bool *bits)
{
    for(unsigned i(0); i < byte_size; ++i)
    {
        bits[i] = (b & 0x01) != 0;
        b >>= 1;
    }
}

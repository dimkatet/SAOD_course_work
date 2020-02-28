#include "shannon_code.h"

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

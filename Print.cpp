#include "Print.hpp"
void printRec(node *s)
{
    int cn = 1;
    node *temp = s;
    if(temp == NULL)
    {
        cout << "Not found" << endl;
        getch();
        return;
    }
    cout << "Num" << "    Author    " << "   Publisher  " << "              Title     " << "            Year  " << " Pages" << endl;
    while(temp!= NULL)
    {
        cout << cn << ")  " <<temp->data.author << "  " << temp->data.publisher << "  "
        << temp->data.title << "  " << temp->data.year << "    " << temp->data.num_of_page << endl;
        //printf("  %d \n", temp->next);
        temp = temp -> next;
        if(cn%20==0){
            cout << "Page: " << cn/20 << endl;
            if(getch()==27) return;
            system("CLS");
            cout << "Num" << "    Author    " << "   Publisher  " << "              Title     " << "            Year  " << " Pages" << endl;
        }
        cn++;
    }
    cout << "End of line." <<endl;
    getch();
    system("CLS");
}

void printArray(record **indexArray, int n)
{
    int page = 0;
    char ch = 0;
    while(1)
    {
        for(int i = page * 20; i < (page + 1) * 20; i++)
        {
             cout << i + 1 << ")  "<< indexArray[i]->author << "  " << indexArray[i]->publisher << "  "
            << indexArray[i]->title << "  " << indexArray[i]->year << "    " << indexArray[i]->num_of_page << endl;
        }
        ch = getch();
        system("CLS");
        switch(ch)
        {
        case 'w': if(page > 0)page--; break;
        case 's': if(page < 199) page++; break;
        case 27: return;
        }

    }
}


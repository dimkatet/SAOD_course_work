#include "Sort.hpp"

void MergeSort(node* &S, int n)
{
	int t, q, r, i, m;
	node *a, *b, *k, *p;
	body c[2];
	a = S; b = S->next;
	k = a; p = b;
	int x = 0;
	while(p!=NULL)
	{
		k->next=p->next;
		k=p;
		p=p->next;
	}
	t = 1;
    node *temp1 = a, *temp2 = b;
    while(temp1!=NULL){
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        temp2 = temp2->next;
    }

	while (t<n)
	{
	    c[0].tail = c[0].head = NULL;
	    c[1].tail = c[1].head = NULL;
		i = 0; m = n;
		while(m>0)
		{
			if (m>=t) q = t;
			else q = m;
			m = m - q;
			if (m>=t) r = t;
			else r = m;
			m = m - r;
			while (q!=0&&r!=0)
			{
				if(!diff(a->data,b->data))
				{
				    if(c[i].tail == NULL)
                    {
                         c[i].tail = c[i].head = a;
                    }
                    else{
                        c[i].tail->next = a;
                        c[i].tail = a;
                    }
					a = a->next;
					q--;

				}
				else
				{

                    if(c[i].tail == NULL)
                    {
                        c[i].tail = c[i].head = b;
                    }
				    else {
                        c[i].tail->next = b;
                        c[i].tail = b;
				    }
					b = b->next;
					r--;

				}
			}
			while(q>0)
			{
			    if(c[i].tail == NULL)
                {
                    c[i].tail = c[i].head = a;
                }
                else{
                    c[i].tail->next = a;
                    c[i].tail = a;
                }
				a = a->next;
				q--;
			}
			while(r>0)
			{
			    if(c[i].tail == NULL)
                {
                    c[i].tail = c[i].head = b;
                }
                else {
                    c[i].tail->next = b;
                    c[i].tail = b;
                }
				b = b->next;
				r--;
			}
			i = 1 - i;
			x++;
		}
		a = c[0].head; b = c[1].head;
		t=2*t;
	}
	c[0].tail->next = NULL;
	S = c[0].head;
}

bool diff(record a, record b)
{
    int i = 0, diff = 0;
    while(a.publisher[i]!='\0'&&b.publisher[i]!='\0')
    {
        diff += a.publisher[i] - b.publisher[i];
        if(diff!=0) break;
        i++;
    }
    i = 0;
    if(diff>0) return true;
    if(diff<0) return false;
    if(diff==0)
    {
        while(a.author[i]!='\0'&&b.author[i]!='\0')
        {
            diff+= a.author[i] - b.author[i];
            if(diff!=0) break;
            i++;
        }
        if (diff>=0) return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertSort(string &str, int n)
{
	char t=0;
	int j=0;
	for (int i=1;i<n;i++)
	{
		t=str[i];
		j=i-1;
		while((j>=0)&&(t>str[j]))
		{
            str[j+1] = str[j];
			j=j-1;
		}
		str[j+1] = t;
	}
}


void InsertSort(std::vector<float> &p, string &str, int n)
{
	float t=0;
	int j=0;
	char ch = 0;
	for (int i=1;i<n;i++)
	{
		t=p[i];
		ch = str[i];
		j=i-1;
		while((j>=0)&&(t>p[j]))
		{
			p[j+1]=p[j];
            str[j+1] = str[j];
			j=j-1;
		}
		p[j+1]=t;
		str[j+1] = ch;
	}
}

void InsertSort(string &str, std::vector<float> &p, int n)
{
	float t=0;
	int j=0;
	char ch = 0;
	for (int i=1;i<n;i++)
	{
		t=p[i];
		ch = str[i];
		j=i-1;
		while((j>=0)&&(ch<str[j]))
		{
			p[j+1]=p[j];
            str[j+1] = str[j];
			j=j-1;
		}
		p[j+1]=t;
		str[j+1] = ch;
	}
}

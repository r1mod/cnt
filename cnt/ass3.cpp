#include<iostream>
#include<string.h>
#define max 26
using namespace std;

struct node
{
    string word,mean;
    node *next;
};

class dictionary
{
    private:
        node *a[max];
    public:
        dictionary()
        {
            for(int i=0;i<max;i++)
            {
                a[i]=NULL;
            }
        }
        int hashf(string w)
        {
            return (w[0]-97);
        }
        void insert(string w,string m)
        {
            node *temp;
            temp=new struct node;
            temp->word=w;
            temp->mean=m;
            temp->next=a[hashf(w)];
            a[hashf(w)]=temp;
        }
        void display()
        {
            node *t;
            for(int i=0;i<max;i++)
            {
                if(a[i]==NULL)
                {
                    cout<<"\n"<<i<<" | "<<"EMPTY";
                }
                else
                {
                    for(t=a[i];t!=NULL;t=t->next)
                    {
                        cout<<"\n"<<i<<" | "<<t->word<<" = "<<t->mean;
                    }
                }
            }
        }
        void search(string w)
        {
            node *t;
            int i=hashf(w),f=0;
            if(a[i]==NULL)
            {
                f=0;
            }
            else
            {
                for(t=a[i];t!=NULL;t=t->next)
                {
                    if(t->word==w)
                    {
                        f=1;
                        break;
                    }
                    
                }
            }
            if(f==0)
            {
                cout<<"\nelement not present!";
            }
            else
            {
                cout<<"\n"<<t->word<<" = "<<t->mean;
            }
        }
        void deletew(string w)
        {
            int i=hashf(w),j=0,f=0,k;
            node *t,*s;
            if(a[i]==NULL)
            {
                f=0;
            }
            else
            {
                for(t=a[i];t!=NULL;t=t->next)
                {
                    j++;
                    if(t->word==w)
                    {
                        f=1;
                        break;
                    }
                    
                }
            }
            if(f==0)
            {
                cout<<"\nelement not present!";
            }
            else
            {
                for(s=a[i],k=0;k<j-2;s=s->next,k++);
                s->next=t->next;
                cout<<"\n"<<t->word<<" = "<<t->mean<<" is deleted!";
                delete t;
            }
        }
        
};


int main()
{
    dictionary d;
    int c=0;
    string w,m;
    while(c<5)
	{
		cout<<"\n1.disp";
		cout<<"\n2.insert";
		cout<<"\n3.search";
		cout<<"\n4.delete";
		cout<<"\n5.exit";
		cout<<"\nenter ur choice:";
		cin>>c;
		switch(c)
		{
			case 1:
				d.display();
				break;
			case 2:
				cout<<"\nenter the word:";	
				cin>>w;
				cout<<"\nenter the meaning:";	
				cin>>m;
				d.insert(w,m);
				break;
			case 3:
			    cout<<"\nenter the word to search:";	
				cin>>w;
				d.search(w);
				break;
			case 4:
			    cout<<"\nenter the word to delete:";	
				cin>>w;
			    d.deletew(w);
			    break;
		}
	}
}




#include<iostream>
#include<string.h>
#define max 10
using namespace std;

struct phonebook
{
    long int no;
    string name;
};

class HashTable 
{
    private:
        phonebook ht[max];
        int size;
    public:
        HashTable()
        {
            for(int i=0;i<max;i++)
            {
                ht[i].no=0;
                ht[i].name="NA";
            }
        }
        
        
        void display()
        {
            for(int i=0;i<max;i++)
            {
                cout<<"\n"<<i<<" | "<<ht[i].no<<" | "<<ht[i].name;
            }
        }
        
        
        int hashf(long int num)
        {
            return num%10;
        }
        
        
        int search(long int num)
        {
            int p=hashf(num);
            if(ht[p].no==0)
            {
                cout<<"\nnumber not present!";
                return -1;
            }

            else
            {
                for(int i=0;i<max;i++)
            	{
            	    int j=(hashf(num)+(i*i));
                    if(ht[p].no==num)
                    {
                        cout<<"\nnumber belongs to:"<<ht[p].name;
                        return p;
                    }
                }
            }
        }
        
        
        void deletep(long int num)
        {
            int p=search(num);
            if(p==-1)
            {
                
            }
            else
            {
                cout<<" is deleted!";
                ht[p].no=0;
                ht[p].name="NA";
            }
        }
        
        
        void insert(long int num,string n)
        {
            	for(int i=0;i<max;i++)
            	{
            	    int j=(hashf(num)+(i*i));
            		if(ht[j].no==0)
            		{
            			ht[j].no=num;
        		        ht[j].name=n;
            			break;
            			
            		}
            		
            	}
        }
        
    
};

int main()
{
	HashTable t;
	int c=0,a;
	long int n;
	string s;
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
				t.display();
				break;
			case 2:
				cout<<"\nenter the number:";	
				cin>>n;
				cout<<"\nenter the name:";	
				cin>>s;
				t.insert(n,s);
				break;
			case 3:
			    cout<<"\nenter the number to search:";	
				cin>>n;
				a=t.search(n);
				break;
			case 4:
			    cout<<"\nenter the number to delete:";	
				cin>>n;
			    t.deletep(n);
			    break;
		}
	}
}

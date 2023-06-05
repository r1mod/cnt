#include<iostream>
#define max 10
using namespace std;

class HashTable 
{
    private:
        int ht[max];
        int size;
    public:
        HashTable()
        {
            for(int i=0;i<max;i++)
                ht[i]=-1;
        }
        
        void display()
        {
            for(int i=0;i<max;i++)
            {
            	cout<<"\n";
                cout<<i<<"|"<<ht[i];
            }
        }
        
        int hashf(int key)
        {
            return key%10;
        }
        
        void insert(int key)
        {
        	if(ht[hashf(key)]==-1)
        		ht[hashf(key)]=key;
        	else
			{
            	for(int i=(hashf(key)+1)%max;i<max;i++)
            	{
            		if(ht[i]==-1)
            		{
            			ht[i]=key;
            			break;
            			
            		}
            		
            	}
            }
        }
        
        int search(int key)
        {
            int p=hashf(key);
            if(ht[p]==-1)
            {
                cout<<"\nnumber not present!";
                return -1;
            }
            if(ht[p]==key)
            {
                cout<<"\nnumber present at:"<<p;
                return p;
            }
            else
            {
                for(int i=(p+1)%max;((i%max)!=p && ht[i%max]!=-1);i=(i+1)%max)
                {
                    if(ht[p]==key)
                    {
                        cout<<"\nnumber present at:"<<p;
                        return p;
                    }
                }
            }
        }
        
        void deletep(int key)
        {
            int p=search(key);
            if(p==-1)
            {
                
            }
            else
            {
                cout<<" is deleted!";
                ht[p]=-1;
            }
        }
        
    
};

int main()
{
	HashTable t;
	int c=0,k,a;
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
				cout<<"\nenter the key:";	
				cin>>k;
				t.insert(k);
				break;
			case 3:
			    cout<<"\nenter the number to search:";	
				cin>>k;
				a=t.search(k);
				break;
			case 4:
			    cout<<"\nenter the number to delete:";	
				cin>>k;
			    t.deletep(k);
			    break;
		}
	}
}

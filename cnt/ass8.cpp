#include<iostream>
#include<string.h>
#include <fstream>
#define max 20
using namespace std;

struct node
{
    string place;
    struct node *next;
    int dis;
};

class graph
{
    private:
        int n;
        struct node *a[max];
        int visited[max];
    public:
        
        graph()
        {
            for(int i=0;i<max;i++)
            {
                a[i]=new struct node;
                a[i]->next=NULL;
                a[i]->place='_';
                a[i]->dis=0;
            }
        }
        
        
        void read()
        {
        	cout<<"\n ENTER NO. OF CITIES:";
        	cin>>n;
        	cout<<"\n ENTER THE PLACES:";
        	for(int i=0;i<n;i++)
        	{
        		cin>>a[i]->place;
        	}
        	string s1,s2;
        	int d;
        	char ans;
        	do
        	{
        		cout<<"\n ENTER THE ROUTE:";
        		cin>>s1>>s2;
        		cout<<"\n ENTER THE DISTANCE IN KILOMETER:";
        		cin>>d;
        		struct node *temp,*t;
        		temp=new struct node;
        		temp->next=NULL;
        		temp->place=s2;
        		temp->dis=d;
        		for(int i=0;i<n;i++)
            	{
            		if(a[i]->place==s1)
            		{
            		    if(a[i]->next==NULL)
            		        a[i]->next=temp;
            		    else
            		    {
            		        t=a[i];
            		        while(t->next!=NULL)
            		            t=t->next;
            		        t->next=temp;    
            		    }    
            		}    
            		    
            	}
        		cout<<"\n IF YOU WANT TO ADD EDGE ENTER Y:";
        		cin>>ans;
        	}while(ans=='Y');
        	
        }
        
        
        
        
        void fread()
        {
            ifstream f1("g.dat");
        	cout<<"\n ENTER NO. OF CITIES:";
        	f1>>n;
        	cout<<"\n ENTER THE PLACES:";
        	for(int i=0;i<n;i++)
        	{
        		f1>>a[i]->place;
        	}
        	string s1,s2;
        	int d;
        	char ans;
        	do
        	{
        		cout<<"\n ENTER THE ROUTE:";
        		f1>>s1>>s2;
        		cout<<"\n ENTER THE DISTANCE IN KILOMETER:";
        		f1>>d;
        		struct node *temp,*t;
        		temp=new struct node;
        		temp->next=NULL;
        		temp->place=s2;
        		temp->dis=d;
        		for(int i=0;i<n;i++)
            	{
            		if(a[i]->place==s1)
            		{
            		    if(a[i]->next==NULL)
            		        a[i]->next=temp;
            		    else
            		    {
            		        t=a[i];
            		        while(t->next!=NULL)
            		            t=t->next;
            		        t->next=temp;    
            		    }    
            		}    
            		    
            	}
        		cout<<"\n IF YOU WANT TO ADD EDGE ENTER Y:";
        		f1>>ans;
        	}while(ans=='y'||ans=='Y');
        }
        
        
        void display()
        {
            struct node *t;
            for(int i=0;i<n;i++)
            {
                if(a[i]!=NULL)
                {
                    t=a[i]->next;
                    while(t!=NULL)
                    {
                        cout<<"\n"<<a[i]->place<<"\t"<<t->place<<"\t"<<t->dis;
                        t=t->next;
                    }
                }
            }
        }
        
        
        void init()
		{
			for(int j=0;j<n;j++)
    		{
    				visited[j]=0;
    		}
		}
        
	
        void dfs(string s)
        {
            int i,j;
        	for(i=0;i<max;i++)
        	{
        	    if(a[i]->place==s)
        	        break;
        	}
        	visited[i]=1;
        	cout<<a[i]->place<<"\t";
        	struct node *t=a[i]->next;
        	while(t!=NULL)
        	{
        	    for(j=0;j<max;j++)
        	    {
        	        if(a[j]->place==t->place)
        	            break;
        	    }
        	    if(!visited[j])
        	        dfs(t->place);
        	    t=t->next;
        	    
        	}    
        }
        
        
        void fe(string s1,string s2)
        {
            int i,j=0;
        	for(i=0;i<max;i++)
        	{
        	    if(a[i]->place==s1)
        	        break;
        	}
        	struct node *t=a[i]->next;
        	while(t!=NULL)
        	{
        	    if(t->place==s2)
        	        j=1;
        	    t=t->next;
        	}
        	if(j==1)
        	    cout<<"\nflight exist";
        	else
        	    cout<<"\nflight doesn't exist";
        }
       
};

int main()
{
    graph g;
    g.fread();
    g.display();
    string s,s1,s2;
    cout<<"\nenter string:";
    cin>>s;
    g.init();
    g.dfs(s);
    cout<<"\nenter route to check existence of flight:";
    cin>>s1>>s2;
    g.fe(s1,s2);
}

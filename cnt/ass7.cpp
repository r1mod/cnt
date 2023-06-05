#include<iostream>
#include<string.h>
#define max 20
using namespace std;


class graph
{
    private:
        int arr[max][max];
        string p[max];
        int visited[max];
        int n;
	public:

    	graph()
    	{
    		for(int i=0;i<max;i++)
    		{
    			for(int j=0;j<max;j++)
    			{
    				arr[i][j]=0;
    			}	
    		}		
    	}
    	
    	
        void read()
        {
        	cout<<"\n ENTER NO. OF PLACES IN MAP:";
        	cin>>n;
        	cout<<"\n ENTER THE PLACES:";
        	for(int i=0;i<n;i++)
        	{
        		cin>>p[i];
        	}
        	string s1,s2;
        	int d;
        	int v1,v2;
        	char ans;
        	do
        	{
        		cout<<"\n ENTER THE ROUTE:";
        		cin>>s1>>s2;
        		cout<<"\n ENTER THE DISTANCE IN METER:";
        		cin>>d;
        		v1=find(p,n,s1);
        		v2=find(p,n,s2);
        		if(v1!=-1 && v2!=-1)
        			arr[v1][v2]=d;
        		else
        			cout<<"\n LOCATION NOT PRESENT!!";
        		cout<<"\n IF YOU WANT TO ADD EDGE ENTER Y:";
        		cin>>ans;
        	}while(ans=='Y');
        	
        }
        
        
        int find(string arr[], int len, string seek)
		{
			for (int i = 0; i < len; ++i)
			{
				if (arr[i] == seek) return i;
			}
			return -1;
		}
		
		
		void display()
		{
			for(int j=0;j<n;j++)
				cout<<"\t"<<p[j];
			for(int i=0;i<n;i++)
    		{
    			cout<<"\n";
    			cout<<p[i];
    			for(int j=0;j<n;j++)
    			{
    				
    				cout<<"\t"<<arr[i][j];
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
        	int i=find(p,n,s);
        	visited[i]=1;
        	cout<<p[i]<<"\t";
        	for(int j=0;j<n;j++)
    		{
    			if(arr[i][j] && !visited[j])
    				dfs(p[j]);
    		}
        }

        void bfs(string s)
        {
        	string s2[n];
        	int f,r;
        	f=r=-1;
        	s2[++r]=s;
        	if(f==-1)
        		f++;
        	while(r!=-1)
        	{
        		string s1=s2[r--];
        		int x=find(p,n,s1);
        		visited[x]=1;
        		cout<<p[x]<<"\t";
        		for(int j=0;j<n;j++)
    			{
    				if(arr[x][j] && !visited[j])
    				{
    				    s2[++r]=s;
                    	if(f==-1)
                    		f++;
    				}	
    			}
        	}
        	
        }
};


int main()
{
	graph g;
	g.read();
	g.display();
	string s;
	cout<<"\nENTER STRING FROM WHICH YOU WANT TO START DFS:";
	cin>>s;
	g.init();
	g.dfs(s);
	cout<<"\nENTER STRING FROM WHICH YOU WANT TO START BFS:";
	cin>>s;
	g.init();
	g.bfs(s);
}

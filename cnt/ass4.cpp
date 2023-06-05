#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *l,*r;
};

class bst
{
    private:
        struct node *root;

        
    public:
        struct node* getr()
        {
            return root;
        }
        
        
        bst()
        {
            root=NULL;
        }
        
        
        void insert(int d)
        {
            struct node *t,*s;
            s=new struct node;
            s->data=d;
            s->l=s->r=NULL;
            if(root==NULL)
            {
                root=s;
            }
            else
            {
                t=root;
                while(1)
                {
                    if(s->data < t->data)
                    {
                        if(t->l == NULL)
                        {
                            t->l=s;
                            break;
                        }
                        else
                            t=t->l;
                    }
                    else
                    {
                        if(t->r == NULL)
                        {
                            t->r=s;
                            break;
                        }
                        else
                            t=t->r;
                    }
                }
            }
        }
        
        
        void inorder(struct node *root)
        {
            if(root!=NULL)
            {
                inorder(root->l);
                cout<<"\t"<<root->data;
                inorder(root->r);
            }
        }
        
        
        void preorder(struct node *root)
        {
            if(root!=NULL)
            {
                cout<<"\t"<<root->data;
                preorder(root->l);
                preorder(root->r);
            }
        }
        
        
        void postorder(struct node *root)
        {
            if(root!=NULL)
            {
                postorder(root->l);
                postorder(root->r);
                cout<<"\t"<<root->data;
            }
        }
        
        
        struct node* search(struct node* root, int key)
        {
	        if (root == NULL || root->data == key)
	            return root;
	        if (root->data < key)
	            return search(root->r, key);
	        if (root->data > key)
	            return search(root->l, key);
	        else 
	            return NULL;
        }
        
        
        void deleted(struct node* root,int d)
        {
            struct node *t=search(root,d);
            struct node *t1,*t2;
            if(t==NULL)
                cout<<"\nelement not present!!";
			else
			{
			    if(t->l==NULL && t->r==NULL)
			    {
					t1=root;
			        while(t1->data==d)
			        {
			        	t2=t1;
			        	if(t1->data > d)
			        		t1=t1->l;
			        	else
			        		t1=t1->r;
			        }
					if(t2->data > d)
						t2->l=NULL;
					else
						t2->r=NULL;
			        delete t;
			        cout<<"\nelement is deleted!!";
			    }
			    if(t->l==NULL || t->r==NULL)
			    {
			        t1=root;
			        while(t1->data==d)
			        {
			        	t2=t1;
			        	if(t1->data > d)
			        		t1=t1->l;
			        	else
			        		t1=t1->r;
			        }
			        if(t2->data > d)
			        {	
			        	if(t->l==NULL)
			        		t2->l=t->r;
			        	else
			        		t2->l=t->l;
			        }		
			        else
			        {	
			        	if(t->l==NULL)
			        		t2->r=t->r;
			        	else
			        		t2->r=t->l;
			        }
			        	
			        delete t;
			        cout<<"\nelement is deleted!!";
			    }
			    else
			    {
			        struct node *m=t;
			        m=m->r;
			        while(m->l!=NULL)
			        {
			            m=m->l;
			        }
			        t1=root;
			        while(t1->data==m->data)
			        {
			        	t2=t1;
			        	if(t1->data > m->data)
			        		t1=t1->l;
			        	else
			        		t1=t1->r;
			        }
			        
			        int s=t->data;
			        t->data=m->data;
			        m->data=s;
			        t2->l=NULL;
			        delete m;
			        cout<<"\nelement is deleted!!";
			    }
			}
				    
        }
 
};


int main()
{
    bst b;
    int c=0,d;
    struct node *t; 
    while(c<6)
	{
		cout<<"\n1.insert";
		cout<<"\n2.inorder";
		cout<<"\n3.preorder";
		cout<<"\n4.postorder";
		cout<<"\n5.search";
		cout<<"\n6.delete";		
		cout<<"\n7.exit";
		cout<<"\nenter ur choice:";
		cin>>c;
		switch(c)
		{
			case 1:
			    cout<<"\nenter the number:";	
				cin>>d;
				b.insert(d);
				break;
			case 2:
			    if(b.getr()==NULL)
                    cout<<"\ntree is empty!!";
                else
				    b.inorder(b.getr());
				break;
			case 3:
			    if(b.getr()==NULL)
                    cout<<"\ntree is empty!!";
                else
			        b.preorder(b.getr());
				break;
			case 4:
			    if(b.getr()==NULL)
                    cout<<"\ntree is empty!!";
                else
			        b.postorder(b.getr());
			    break;
            case 5:
                cout<<"\nenter the number to search:";	
				cin>>d;
				t=b.search(b.getr(),d);
				if(t==NULL)
				    cout<<"\nelement not present!!";
				else
				    cout<<"\nelement found!!";
				break;
			case 6:
			    cout<<"\nenter the number to delete:";	
				cin>>d;
				b.deleted(b.getr(),d);
			    break;
		}
	}
}


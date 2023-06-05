#include<iostream>
#define max 20
using namespace std;

struct node
{
    char data;
    struct node *l,*r;
};

class stack
{
    public:
        struct node* *s;
        int top=-1;
    
        stack()
        {
            s=new struct node*[max];
        }
        
        int isempty()
        {
            if(top==-1)
                return 1;
            else
                return 0;
        }
        
        void push(struct node *t)
        {
            s[++top]=t;
        }
        
        struct node* pop()
        {
            return s[top--];
        }
        
        int isfull()
        {
            if(top==max)
                return 1;
            else
                return 0;
        }
        
};

class exp:protected stack
{
    private:
        struct node *root;
        
    public:
        
        exp()
        {
            root=NULL;
        }
        
        
        
        void create()
        {   
            struct node *t,*t1,*t2;
            string pf;
            cout<<"\nENTER POSTFIX EXPRESSION:";
            cin>>pf;
            int i=0;
            while(pf[i]!='\0')
            {
                char ch=pf[i++];
                t=new struct node;
                t->data=ch;
                t->l=t->r=NULL;
                if(ch>='A' && ch<='Z')
                    push(t);
                else
                {
                    t1=pop();
                    t2=pop();
                    t->l=t1;
                    t->r=t2;
                    push(t);
                }
            }
            root=pop();
        }
        
        void inorder(struct node *root)
        {
            if(root!=NULL)
            {
                inorder(root->l);
                cout<<root->data<<"\t";
                inorder(root->r);
            }
        }
        
        void preorder(struct node *root)
        {
            if(root!=NULL)
            {
                cout<<root->data<<"\t";
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
                cout<<root->data<<"\t";
            }
        }
        
        struct node* getr()
        {
            return root;
        }
};



int main()
{
    exp e;
    e.create();
    e.inorder(e.getr());
    cout<<"\n";
    e.preorder(e.getr());
    cout<<"\n";
    e.postorder(e.getr());
}

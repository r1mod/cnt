#include<iostream>
using namespace std;

struct node
{
    string word,mean;
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
        
        
        void insert(string w, string m)
        {
            struct node *t,*s;
            s=new struct node;
            s->word=w;
            s->mean=m;
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
                    if(s->word < t->word)
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
                cout<<"\n"<<root->word<<" : "<<root->mean;
                inorder(root->r);
            }
        }
        
        
        void des(struct node *root)
        {
            if(root!=NULL)
            {
                des(root->r);
                cout<<"\n"<<root->word<<" : "<<root->mean;
                des(root->l);
            }
        }
        
        
        void preorder(struct node *root)
        {
            if(root!=NULL)
            {
                cout<<"\n"<<root->word<<" : "<<root->mean;
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
                cout<<"\n"<<root->word<<" : "<<root->mean;
            }
        }
        
        
        void search(struct node* root,string w)
        {
	        if (root == NULL)
	            cout<<"\nnot found";
	        else if (root->word == w)
	            cout<<root->word<<" : "<<root->mean;    
	        else if (root->word < w)
	            return search(root->r, w);
	        else if (root->word > w)
	            return search(root->l, w);
	        else
	            cout<<"\nnot found";
        }
        
        
         void update(struct node* root,string w)
        {
            string m;
	        if (root == NULL)
	            cout<<"\nnot found";
	        else if (root->word == w)
	        {
	            cout<<"\nenter new meaning";
	            cin>>m;
	            root->mean=m;
	        }        
	        else if (root->word < w)
	            return update(root->r, w);
	        else if (root->word > w)
	            return update(root->l, w);
	        else
	            cout<<"\nnot found";
        }
        
        
        void smallest(struct node* root)
        {
            while(root->l!=NULL)
            {
                root=root->l;
            }
            cout<<"\nsmallest word:";
            cout<<root->word<<" : "<<root->mean;
        }
        
        
        void largest(struct node* root)
        {
            while(root->r!=NULL)
            {
                root=root->r;
            }
            cout<<"\nlargest word:";
            cout<<root->word<<" : "<<root->mean;
        }
        
        struct node* minValueNode(struct node* node)
        {
            struct node* current = node;
            while (current && current->l != NULL)
                current = current->l;
            return current;
        }
 

        struct node* deleteNode(struct node* root, string w)
        {
            if (root == NULL)
                return root;
            if (w < root->word)
                root->l = deleteNode(root->l, w);
            else if (w > root->word)
                root->r = deleteNode(root->r, w);
            else 
            {
                if (root->l == NULL and root->r == NULL)
                    return NULL;
                else if (root->l == NULL) 
                {
                    struct node* temp = root->r;
                    free(root);
                    return temp;
                }
                else if (root->r == NULL) 
                {
                    struct node* temp = root->l;
                    free(root);
                    return temp;
                }
                struct node* temp = minValueNode(root->r);
                root->word = temp->word;
                root->r = deleteNode(root->r, temp->word);
            }
            return root;
        }

};


int main()
{
    bst b;
    string w,m;
    int c=0;
    struct node *t; 
    while(c<11)
	{
		cout<<"\n1.insert";
		cout<<"\n2.inorder";
		cout<<"\n3.preorder";
		cout<<"\n4.postorder";
		cout<<"\n5.search";		
		cout<<"\n6.smallest element";
		cout<<"\n7.largest element";
		cout<<"\n8.update";
		cout<<"\n9.delete";
		cout<<"\n10.descending order";
		cout<<"\n11.exit";
		cout<<"\nenter ur choice:";
		cin>>c;
		switch(c)
		{
			case 1:
			    cout<<"\nenter the word:";	
				cin>>w;
				cout<<"\nenter the meaning:";	
				cin>>m;
				b.insert(w,m);
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
                cout<<"\nenter the word to search:";	
				cin>>w;
				b.search(b.getr(),w);
				break;
			case 6:
			    b.smallest(b.getr());
				break;
			case 7:
			    b.largest(b.getr());
				break;
			case 8:
                cout<<"\nenter the word to update meaning:";	
				cin>>w;
				b.search(b.getr(),w);
				break;
			case 9:
                cout<<"\nenter word to delete:";
                cin>>w;
                t=b.deleteNode(b.getr(),w);
                cout<<"Inorder traversal of the modified tree \n";
                b.inorder(b.getr());
				break;
			case 10:
			    if(b.getr()==NULL)
                    cout<<"\ntree is empty!!";
                else
				    b.des(b.getr());
				break;
		}
	}
}

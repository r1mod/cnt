#include<iostream>
using namespace std;

struct AVLnode
{
	AVLnode *left, *right;
	int ht;
	string keyword, meaning;
};
class AVLTree
{
	
	public:
		AVLnode *root;
		AVLTree()
		{
			root=NULL;
		}
		AVLnode* insert(AVLnode *root, string newkey, string mean);
		int height(AVLnode *);
		int BF(AVLnode *);
		AVLnode *LL(AVLnode *);
		AVLnode *LR(AVLnode *);
		AVLnode *RR(AVLnode *);
		AVLnode *RL(AVLnode *);
		AVLnode *RotateLeft(AVLnode *);
		AVLnode *RotateRight(AVLnode *);
		void ascending(AVLnode *);
		void descending(AVLnode *);
		void create();
		AVLnode *search(AVLnode *, string);
};

        void AVLTree::create()
        {
	        char ch;
	        string word,mean;
	        do{
		        cout<<"Enter Word : "<<endl;
		        cin>>word;
		        cout<<"Enter Meaning  : "<<endl;
		        cin>>mean;
		        root=insert(root,word,mean);
		        cout<<"Do you want to add more ?(y/n)"<<endl;
		        cin>>ch;
		        }while(ch=='y');
        }

        AVLnode* AVLTree::insert(AVLnode *root, string newkey, string mean)
        {
	        AVLnode *curr;
	        int lh, rh;
	        if(root == NULL)
	        {
		        curr = new AVLnode;
		        curr->keyword = newkey;
		        curr->meaning = mean;
		        curr->ht = 0;
		        curr->left = NULL;
		        curr->right = NULL;
		        root = curr;
	        }
	        else
	        {
		        if(newkey<root ->keyword)
		        {
			        root->left = insert(root->left, newkey, mean);
			        if(BF(root) == 2)
			        {
				        if(newkey<root->left->keyword)
				        {
					        root = LL(root);
				        }
				        else
				        {
					        root = LR(root);
				        }
			        }
		        }
		        
		        else
		        {
			        if(newkey>root->keyword)
			        {
				        root->right = insert(root->right, newkey, mean);
				        if(BF(root) == -2)
				        {
					        if(newkey > root->right->keyword)
					        {
						        root = RR(root);
					        }
					        else
					        {
						        root = RL(root);
					        }
				        }
			        }
			        else
			        {
				        cout<<"Duplicate."<<endl;
			        }
		        }
	        }
		        root->ht = height(root);
		        return root;
        }

        AVLnode *AVLTree :: RotateLeft(AVLnode *x)
        {
	        AVLnode *y;
	        y=x->right;
	        x->right=y->left;
	        y->left=x;
	        return y;
        }
        AVLnode *AVLTree :: RotateRight(AVLnode *x)
        {
	        AVLnode *y;
	        y=x->left;
	        x->left=y->right;
	        y->right=x;
	        return y;
        }
        AVLnode *AVLTree :: LL(AVLnode *T)
        {
	        cout<<"LL Rotation ."<<endl;
	        T=RotateRight(T);
	        return T;
        }
        AVLnode *AVLTree :: LR(AVLnode *T)
        {
	        cout<<"LR Rotation .";
	        T->left=RotateLeft(T->left);
	        T=RotateRight(T);
	        return T;
        }
        AVLnode *AVLTree :: RR(AVLnode *T)
        {
	        cout<<"RR Rotation ."<<endl;
	        T=RotateLeft(T);
	        return T;
        }
        AVLnode *AVLTree :: RL(AVLnode *T)
        {
	        cout<<"RL Rotation .";
	        T->right=RotateRight(T->left);
	        T=RotateLeft(T);
	        return T;
        }
        int AVLTree :: height(AVLnode *T)
        {
	        int h=0;
	        int hr,hl;
	        if(T==NULL)
	            return 0;
	        if(T->left==NULL && T->right ==NULL)
	        {
		        hl=height(T->left);
		        hr=height(T->right);
		        if(hl<hr)
			        return hr+1;
		        else 
		         	return hl+1;
	        }
        }

        int AVLTree :: BF(AVLnode *T)
        {
	        int hr,hl;
	        hl=height(T->left);
	        hr=height(T->right);
	        return hl-hr;
        }

        void AVLTree:: ascending(AVLnode *root)
        {

	        if(root!=NULL)
	        {
		        
		        ascending(root->left);
		        cout<<root->keyword<<" -->  "<<root->meaning<<endl;
		        ascending(root->right);
		        
	        }
	        
        }
        void AVLTree:: descending(AVLnode *root)
        {
	        
	        if(root!=NULL)
	        {
		        
		        descending(root->right);
		        cout<<root->keyword<<" -->  "<<root->meaning<<endl;
		        descending(root->left);
	        }
	        
        }
        AVLnode *AVLTree:: search(AVLnode *root, string key)
        {
	        if (root == NULL || root->keyword == key)
	            return root;
	        if (root->keyword < key)
	            return search(root->right, key);
	        if (root->keyword > key)
	            return search(root->left, key);
	        else 
	            return NULL;
        }

int main()
{
  AVLTree tree;
  string w;
  AVLnode *t;
  int choice;
  while(choice!=6)
  	{
  		cout<<endl;
  		cout<<"------Menu--------"<<endl;
  		cout<<"1.Add Dictionary  "<<endl;
  		cout<<"2.In Ascending Order "<<endl;
  		cout<<"3.In Descending Order "<<endl;
  		cout<<"4.Clear All Dictionary "<<endl;
  		cout<<"5.Search"<<endl;
  		cout<<"5.Exit"<<endl;
  		cout<<"------------------------"<<endl;
  		cout<<"Enter your choice : "<<endl;
  		cin>>choice;
  		switch(choice)
  		{
  			case 1:
  					tree.create();
  					break;
  			case 2:
  					if(tree.root==NULL)
  					{
  						cout<<"Dictionary is empty....."<<endl;
  					}
  					else
  					{
  						 tree.ascending(tree.root);
  					}
  					break;
  			case 3:
  					if(tree.root==NULL)
  					{
  						cout<<"Dictionary is empty....."<<endl;
  					}
  					else
  					{
  						 tree.descending(tree.root);
  					}
  					break;
  			case 4:
  					tree.root=NULL;
  					cout<<"All Data is Cleared...."<<endl;
  					break;
  			case 5:
  			        cout<<"\nenter the word to search:";	
				    cin>>w;
				    t=tree.search(tree.root,w);
				    if(t==NULL)
				        cout<<"\nelement notfound!!";
				    else
				    {
				        cout<<"\nelement found!!";
				        cout<<"\n"<<t->keyword<<" -->  "<<t->meaning;
				    }    
				    break;		
  			case 6:
  					cout<<"Exit...."<<endl;
  					break;
  			default: 
  					cout<<"Invalid choice..."<<endl;
  					break;					
  		}
  		
  	}
  
}

#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root;
node *root2;
node * create()
{
    node *n;
    int d;
    cout<<"Enter a digit to enter or -1 for no node"<<"\n";
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    n=new node;
    n->data=d;
    cout<<"Enter Left Child or -1"<<"\n";
    n->left=create();
    cout<<"Enter Right Child or -1"<<"\n";
    n->right=create();
    return n;
}
void preorderprint(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data;
        cout<<" ";
        preorderprint(root->left);
        preorderprint(root->right);
    }
}
void inorderprint(node *root)
{
    if(root!=NULL)
    {
        inorderprint(root->left);
        cout<<" ";
        cout<<root->data;
        cout<<" ";
        inorderprint(root->right);
    }    
}
void postorderprint(node *root)
{
    if(root!=NULL)
    {
        postorderprint(root->left);
        postorderprint(root->right);
        cout<<root->data;
        cout<<" ";
    }
}
int countleaves(node *root)
{
  int ctr=0;
  if(root==NULL)
  {
    //cout<<"Null\n"<<ctr;
    return ctr;   
  }
  if(root->left==NULL && root->right==NULL)
  {
    ctr++;
    //cout<<"Leaf Node\n"<<ctr;
    return ctr;
  }
  else
  {
    //cout<<"Recursion Left for"<<root->data<<"\n";
    ctr+=countleaves(root->left);
    //cout<<"Recursion Right for"<<root->data<<"\n";
    ctr+=countleaves(root->right);
    //cout<<ctr<<"\n";
    return ctr;
  }
}
void mirror(node *root)
{
    if(root->left==NULL && root->right==NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    node *temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}
int main()
{
    int i=0;
    cout<<"Enter the no. of operation you want to perform\n";
    cout<<"1.Create Tree.\n2.Print in inorder.\n3.Print in preorder.\n4.Print in Postorder.\n5.Count No. Of Leaves.\n6.Mirror Tree.\n7.Exit.\n";
    do
    {
        cout<<"Enter the no. of the operation you want to perform:";
        cin>>i;
        switch(i)
        {
        case 1:     
            root=create();
            break;
        case 2:     
            inorderprint(root);
            break;
        case 3: 
            preorderprint(root);
            break;
        case 4: 
            postorderprint(root);
            break;
        case 5:
            cout<<countleaves(root);
            break;
        case 6: 
            mirror(root);
            break;
        case 7:
            cout<<"Hasta La Vista,Baby!!!";
            break;
        }
    }
    while(i!=7);
    return 0;
}
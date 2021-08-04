#include<iostream>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
};
/*node * create()
{
    node *n;
    int d=0;
    while(d!=-1)
    {
        cout<<"Enter data or -1 for no node";
        cin>>d;
        if(d==-1)
        {
            return 0;
        }
        n=new node;
        n->data=d;
        cout<<"Enter left node:";
        n->left=create();
        cout<<"Enter right node";
        n->right=create();
    }
}*/
node *create()
{
    node *n=NULL,*temp,*root=NULL,*next;
    int d=0;
    while(d!=-1)
    {
        cout<<"Enter the data or -1 to exit";
        cin>>d;
        if(d!=-1)
        {
            temp=root;
            n=new node;
            n->data=d;
            n->right=NULL;
            n->left=NULL;
            if(root==NULL)
            {
                root=n;
            }
            else
            {
                if(temp->data<d)            //Right Side
                {
                    while(temp->data<d && temp->right!=NULL)
                        temp=temp->right;
                    if(temp->right==NULL)
                    {
                        temp->right=n;
                    }
                    if(temp->right!=NULL)  
                    {
                        next=temp->right;
                        temp->right=n;
                        n->right=next;
                    }
                    if(temp->right->data<d)
                    {
                        temp->left=n;
                    }
                }
                else                
                {
                    if(temp->data>d)          //Left Side
                    {
                        while(temp->data>d && temp->left!=NULL)
                            temp=temp->left;
                        if(temp->left==NULL)
                        {
                            temp->left=n;
                        }
                        if(temp->left!=NULL)   //Insert at middle of 2 nodes
                        {
                            next=temp->left;
                            temp->left=n;
                            n->left=next;
                        }
                        if(temp->left->data>d)  //Insert in right sub tree
                            temp->right=n;
                    }
                }

            }    
        }
    }
    return root;
}
node * print(node *root)        //Experiment
{
    node *lft,*rgt,*l,*r;
    if(root!=NULL)
    {
        lft=root->left;
        rgt=root->right;
        cout<<root->data<<" ";
        l=print(lft);
        r=print(rgt);
    }
    else
    {
        return NULL;
    }
}
int main()
{
    node *root,*temp;
    root=create();
    temp=print(root);
}
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
};
node *create()
{
    node *n=NULL,*temp=NULL,*root=NULL;
    int d=0,i;
    while(d!=-1)
    {
        cin>>d;
        if(d!=-1)
        {
            n=new node;
            n->data=d;
            n->right=NULL;
            n->left=NULL;
            temp=root;
            if(root==NULL)
                root=n;
            else
            {
                if(temp->data<d)
                {
                    while(temp->data<d)
                        temp=temp->left;
                    temp->left=n;    
                }
                else
                {
                    if(temp->data>d)
                    {
                        while(temp->data>d)
                            temp=temp->right;
                        temp->right=n;    
                    }
                }

            }    
        }
    }
}
int main()
{
    node *root;
    root=create();
}
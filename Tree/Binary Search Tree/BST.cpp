#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
node *root;
node * insert(node *root,int d)
{
    node *n;
    if(root==NULL)
    {
        n=new node(d);
        return n;
    }
    else
    {
        if(d<root->data)
        {
            root->left=insert(root->left,d);
        }
        else
        {
            if(d>root->data)
            {
                root->right=insert(root->right,d);
            }
        }
    }
}
void create()
{
    int d=0;
    while (d!=-1)
    {
        cout<<"Enter a no. or -1 to exit.";
        cin>>d;
        if(d!=-1)
        {
            root=insert(root,d);
        }
    }
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void search(node *root,int d)
{
    while(root!=NULL)
    {
    if(root!=NULL)
    {
        if(d<root->data)
            root=root->left;
        else
        {
            if(d>root->data)
                root=root->right;
            else
            {
                cout<<"Found";
                return;
            }
        }
    }
    else
        cout<<"Not Found";
    }
}
node * inordersuccsr(node *root)
{
    while(root && root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node * delet(node *root,int d)
{
    if(root->data>d)
    {
        root->left=delet(root->left,d);
    }
    else if(root->data<d)
    {
        root->right=delet(root->right,d);
    }
    else
    {
        /*if(root->left==NULL && root->right==NULL)
        {
            return NULL;
        }*/
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            free(temp);
            return temp;
        }
        node *temp=inordersuccsr(root->right);
        root->data=temp->data;
        root->right=delet(root->right,temp->data);
    }
    return root;
}
void twochild(node *root)
{

}
int main()
{
    create();
    inorder(root);
    search(root,5);
    delet(root,7);
    inorder(root);
    return 0;
}

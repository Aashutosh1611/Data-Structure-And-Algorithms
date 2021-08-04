#include<iostream>
using namespace std;
struct node{
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
node * create()
{
    int d;
    cout<<"Enter a data or -1 to exit";
    cin>>d;
    if(d==-1)
        return NULL;
    node *root=new node(d);
    root->right=create();
    root->left=create();
}
void printin(node *root)
{
    if(root!=NULL)
    {
        printin(root->left);
        cout<<root->data<<" ";
        printin(root->right);
    }
}
void printpre(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        printpre(root->left);
        printpre(root->right);
    }
}
void printpost(node *root)
{
    if(root!=NULL)
    {
        printpost(root->left);
        printpost(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    node *root;
    int j;
    root=create();
    cout<<"Which order to print?\n1.Inorder\n2.Preorder\n3.Postorder\n";
    cin>>j;
    switch(j)
    {
        case 1:     printin(root);
                    break;
        case 2:     printpre(root);
                    break;
        case 3:     printpost(root);
                    break;
    }
    return 0;
}
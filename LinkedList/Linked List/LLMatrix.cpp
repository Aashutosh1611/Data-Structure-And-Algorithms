#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *down;
    Node(int x)
    {
        data=x;
        right=NULL;
        down=NULL;
    }
};
Node* constructLinkedMatrix(int mat[3][3], int n)
{
    Node *root=NULL,*temp,*prev,*head[3],*a;
    cout<<"Initialization"<<"\n";
    int i,j,d;
    for(i=0;i<n;i++)
        head[i]=NULL;
    cout<<"NULL"<<"\n";
    for(i=0;i<n;i++)
    {
        prev=NULL;
        temp=NULL;
        for(j=0;j<n;j++)
            {
                d=mat[i][j];
                temp=new Node(d);
                if(head[i]==NULL)
                    head[i]=temp;
                else
                    prev->right=temp;
                prev=temp;    
            }
    }
    head[0]=root;
    for(i=0;i<n;i++)
    {
        head[i+1]=a;
        while(head[i]!=NULL)
        {
            head[i]->down=a;
            head[i]=head[i]->right;
            a=a->right;
        }
    }
    return root;
}
void print(Node *root)
{
    Node *rp,*dp;
    dp=root;
    while(dp)
    {
        rp=dp;
        while(rp)
        {
            cout<<rp->data<<" ";
            rp=rp->right;
        }
        dp=dp->down;
    }
}
int main()
{
    Node *root;
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    root=constructLinkedMatrix(arr,3);
    print(root);
    return 1;
}
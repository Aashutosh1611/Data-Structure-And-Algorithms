#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void print(node *root)
{
    node *temp=root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node * create()
{
    node *root=NULL,*n,*prev;
    int d=-1;
    while(d!=0)
    {
        cout<<"Enter a no. or 0 to exit";
        cin>>d;
        if(d!=0)
        {
        n=new node;
        n->data=d;
        n->next=NULL;
        if(root==NULL)
            root=n;
        else
            prev->next=n;
        prev=n;
        }    
    }
    return root;
}
void insertend(node *root)
{
    int d;
    cout<<"Enter the data:";
    cin>>d;
    node *n;
    while(root->next!=NULL)
        root=root->next;
    n=new node;
    n->data=d;
    n->next=NULL;
    root->next=n;
}
void deletend(node *root)
{
    int d;
    while(root->next->next!=0)
        root=root->next;
    d=root->next->data;
    root->next=NULL;
    cout<<"Deleted Data:"<<d<<"\n";
}
node * insertbegin(node *root)
{
    int d;
    node *n;
    cout<<"Enter Data to enter:";
    cin>>d;
    n=new node;
    n->data=d;
    n->next=root;
    return n;
}
node * deletebegin(node *root)
{
    node *n;
    n=root;
    root=root->next;
    n->next=NULL;
    return root;
}
void insert(node *root)
{
    node *n;
    int i,pos,d;
    cout<<"Enter the position to insert";
    cin>>pos;
    cout<<"Enter the data to be inserted:";
    cin>>d;
    n=new node;
    n->data=d;
    n->next=NULL;
    for(i=1;i<pos-1 && root!=NULL;i++)
        root=root->next;
    if(root==NULL)
        cout<<"No such position";
    else
    {
        n->next=root->next;
        root->next=n;
    }    
}
void delet(node *root)
{
    node *temp;
    int d,pos,i;
    cout<<"Enter the position you want to delete data:";
    cin>>pos;
    for(i=1;i<pos-1 && root!=NULL;i++)
    {
        root=root->next;
    }
    if(root==NULL)
        cout<<"No such Position";
    else
    {
        temp=root->next;
        temp=temp->next;
        root->next=temp;
    }    
}
void search(node *root)
{
    int d,ctr=1;
    cout<<"Enter The data to search:";
    cin>>d;
    while(root->next!=NULL)
    {
        if(d==root->data)
            break;
        root=root->next;
        ctr++;
    }
    cout<<"Found at "<<ctr<<"Positon.\n";
}
void add(node *root)
{
    int sum=0;
    while(root!=NULL)
    {
        sum+=root->data;
        root=root->next;
    }
    cout<<"The Sum is:"<<sum;
}
void avg(node *root)
{
    int sum=0,ctr=0;
    float ave;
    while(root!=NULL)
    {
        sum+=root->data;
        ctr++;
        root=root->next;
    }
    ave=(sum/ctr);
    cout<<"The average of the dataes are:"<<ave;
}
int main()
{
    node *root;
    int j;
    cout<<"List of Operations--->\n1.Create a Linked List.\n2.Print a Linked List.\n3.Insert an element at the end of list.\n4.Delete an element at the end of list.\n5.Insert an element at the beggining of the list.\n6.Delete an element at the beggining of the list.\n7.Insert an element at a given position.\n8.Delete an element at a given position.\n9.Search an element.\n10.Add all the elemnts of the list.\n11.Print Average of the Elements.\n12.Exit.\n";
    do
    {
        cout<<"Enter the no. of the operation you want to perform:";
        cin>>j;
        switch(j)
        {
        case 1:     
            root=create();
            break;
        case 2:    
            print(root);
            break;
        case 3:
            insertend(root);
            break;
        case 4:     
            deletend(root);
            break;
        case 5:     
            root=insertbegin(root);
            break;
        case 6:     
            root=deletebegin(root);
            break;
        case 7:     
            insert(root);
            break;
        case 8:     
            delet(root);
            break;
        case 9:     
            search(root);
             break;
        case 10:    
            add(root);
            break;
        case 11:    
            avg(root);
            break;
        case 12:    
            cout<<"BYE BYE!!";
            break;
        }
    }
    while(j!=12);
    return 0;
}
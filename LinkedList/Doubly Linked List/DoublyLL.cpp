#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node * create()
{
    node *root=NULL,*n,*temp=NULL;
    int d=-1;
    while(d!=0)
    {
        cout<<"Enter a no. or 0 to exit:";
        cin>>d;
        if(d!=0)
        {
            n=new node;
            n->data=d;
            n->next=NULL;
            n->prev=NULL;
            if(root==NULL)
                root=n;
            else
            {
                n->prev=temp;
                temp->next=n;
            }
            temp=n;    
        }
    }
    return root;
}
void print(node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<"\n";
}
void insertend(node *root)
{   
    node *temp,*n;
    int d;
    cout<<"Enter the data:";
    cin>>d;
    while(root->next!=NULL)
        root=root->next;
    n=new node;
    n->data=d;
    n->next=NULL;
    root->next=n;
    n->prev=root;    
}
void deletend(node *root)
{
    node *temp;
    int d;
    while(root->next->next!=NULL)
        root=root->next;
    temp=root->next;    
    d=temp->data;   
    temp->prev=NULL;
    root->next=NULL;
    cout<<"Deleted data is:"<<d<<"\n"; 
}
node * insertbegin(node *root)
{
    node *n;
    int d;
    cout<<"Enter the data:";
    cin>>d;
    n=new node;
    n->data=d;
    n->prev=NULL;
    n->next=root;
    root->prev=n;
    return n;
}
node * deletbegin(node *root)
{
    int d;
    node *temp;
    temp=root;
    root=root->next;
    root->prev=NULL;
    temp->next=NULL;
    d=temp->data;
    cout<<"Deleted data is:"<<d<<"\n";
}
void insert(node *root)
{
    int pos,d,i;
    node *n,*temp;
    cout<<"Enter the position to insert data:";
    cin>>pos;
    cout<<"Enter the data:";
    cin>>d;
    for(i=1;i<pos-1 && root!=NULL;i++)
    {
        root=root->next;
    }
    if(root==NULL)
        cout<<"No such position";
    else
    {    
        n=new node;
        n->data=d;
        temp=root;
        root=root->next;
        n->prev=temp;
        temp->next=n;
        root->prev=n;
        n->next=root;
    }        
}
void delet(node *root)
{
    int d,n,i;
    node *temp;
    cout<<"Enter the position to delete data:";
    cin>>n;
    for(i=1;i<n-1 && root!=NULL;i++)
        root=root->next;
    temp=root->next;
    d=temp->data;    
    temp=temp->next;
    temp->prev=root;
    root->next=temp;
    cout<<"Deleted data is:"<<d<<"\n";    
}
void max(node *root)
{
    int m=0;
    while(root!=NULL)
    {
        if(root->data>m)
            m=root->data;
        root=root->next;    
    }
    cout<<"Maximum element is:"<<m<<"\n";
}
void add(node *root)
{
    int sum=0;
    while(root!=NULL)
    {
        sum+=root->data;
        root=root->next;
    }
    cout<<"The sum of all elements:"<<sum<<"\n";
}
void count(node *root)
{
    int ctr=0;
    while(root!=NULL)
    {
        root=root->next;
        ctr++;
    }
    cout<<"The no. of elements are:"<<ctr<<"\n";
}
void search(node *root)
{
    int d,i=1;
    cout<<"Enter the element to search:";
    cin>>d;
    while(root!=NULL)
    {
        if(d==root->data)
        {
            cout<<"Element found at "<<i+1<<" position";
            break;
        }
        i++;
        root=root->next;
    }
    if(root==NULL)
        cout<<"No such element"<<"\n";
}
int main()
{
    node *root;
    int j;
    cout<<"List of Operations--->\n1.Create a Linked List.\n2.Print a Linked List.\n3.Insert an element at the end of list.\n4.Delete an element at the end of list.\n5.Insert an element at the beggining of the list.\n6.Delete an element at the beggining of the list.\n7.Insert an element at a given position.\n8.Delete an element at a given position.\n9.Search an element.\n10.Add all the elemnts of the list.\n11.Print max of the Elements.\n12.No. of elements.\n13.Exit.\n";
    do
    {
        cout<<"Enter the no. of operation you want to perform:";
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
            root=deletbegin(root);
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
            max(root);
            break;
        case 12:    
            count(root);
            break;
        case 13:
            cout<<"BYE BYE!!!";
            break;    
        }
    } while (j!=13);
    return 0;
}
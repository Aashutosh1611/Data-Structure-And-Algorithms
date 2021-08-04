#include <bits/stdc++.h>
using namespace std;
struct object
{
    int wei,pro;
    float rat;
};
void sort(object obj[100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(obj[i].rat>obj[j].rat)
            {
                int temp;
                float t;
                temp=obj[i].wei;
                obj[i].wei=obj[j].wei;
                obj[j].wei=temp;
                temp=obj[i].pro;
                obj[i].pro=obj[j].pro;
                obj[j].pro=temp;
                t=obj[i].rat;
                obj[i].rat=obj[j].rat;
                obj[j].rat=t;
            }
        }
    }
}
float knapsack(object obj[100],int n,int k)
{
    float sol=0;
    int i,cw=0;
    sort(obj,n);
    for(i=0;i<n;i++)
    {
        if(obj[i].wei+cw<=k)
        {
            sol+=obj[i].pro;
            cw+=obj[i].wei;
        }
        else
        {
            float lft=k-cw;
            float r=(float)lft/(float)obj[i].wei;
            sol+=obj[i].pro*r;
            break;
        }
    }
    return sol;
}
int main()
{
    object obj[100];
    int i,n,k;
    float sol;
    cout<<"Enter Maximum Carry weight of bag:";
    cin>>k;
    cout<<"Enter no. Of Objects:";
    cin>>n;
    cout<<"Enter profit and weight for each Objects:";
    for(i=0;i<n;i++)
    {
        cin>>obj[i].pro;
        cin>>obj[i].wei;
        obj[i].rat=(float)obj[i].pro/(float)obj[i].wei;
    }
    sol=knapsack(obj,n,k);
    cout<<"The Maximum Profit Can be:"<<sol;
    return 0;
}
#include<bits/stdc++.h>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
struct job
{
    int pro;
    int dedln;
};
void srt(job jb[100],int n)
{
    int i,j=1,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(jb[i].pro>jb[j].pro)
            {
                temp=jb[i].pro;
                jb[i].pro=jb[j].pro;
                jb[j].pro=temp;

                temp=jb[i].dedln;
                jb[i].dedln=jb[j].dedln;
                jb[j].dedln=temp;
            }
        }
    }
}
int maxtim(job jb[100],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(jb[i].dedln>max)
            max=jb[i].dedln;
    }
    return max;
}
int maxprofit(job jb[100],int n)
{
    int slt[100];
    int i=0,mxtm,j=0,max=0;
    srt(jb,n);
    mxtm=maxtim(jb,n);
    for(i=0;i<mxtm;i++)
    {
        slt[i]=0;
    }
    i=0;
    for(i=0;i<n;i++)
    {
        for (j=min(n, jb[i].dedln)-1;j>=0;j--)
       {
          if (slt[j]==0)
          {
            max+=jb[i].pro;
            slt[j]=1; 
            break;
          }
       }
    }
    return max;
}
int main()
{
    job jb[100];
    int n,i;
    int max;
    cout<<"Enter The No. of Jobs:";
    cin>>n;
    cout<<"Enter the job Profit & Deadline"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>jb[i].pro;
        cin>>jb[i].dedln;
    }
    max=maxprofit(jb,n);
    cout<<"The Max Profit is:"<<max;
    return 0;
}
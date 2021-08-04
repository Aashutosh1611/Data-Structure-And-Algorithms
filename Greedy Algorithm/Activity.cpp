#include<bits/stdc++.h>
using namespace std;
struct acttime
{
    int strt;
    int end;
};
void srt(acttime t[100],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i].strt<t[j].strt)
            {
                temp=t[i].strt;
                t[i].strt=t[j].strt;
                t[j].strt=temp;

                temp=t[i].end;
                t[i].end=t[j].end;
                t[j].end=temp;
            }
        }
    }
}
int maxactivity(acttime t[100],int n)
{
    srt(t,n);
    int ct=0,max=0;
    for(int i=0;i<n;i++)
    {
        if(ct<=t[i].strt)
        {
            max++;
            ct=t[i].end;
        }
    }
    return max;
}
int main()
{
    acttime t[100];
    int n,i,max;
    cout<<"Enter Number of activity:";
    cin>>n;
    cout<<"Enter Start Time and End Time"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>t[i].strt;
        cin>>t[i].end;
    }
    max=maxactivity(t,n);
    cout<<"The Maximum Number of Activity:"<<max;
    return 0;
}
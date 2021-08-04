#include<bits/stdc++.h>
#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct petrolpump
{
    int dis;
    int fuel;
};
void srt(petrolpump p[100],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i].dis<p[j].dis)
            {
                temp=p[i].dis;
                p[i].dis=p[j].dis;
                p[j].dis=temp;

                temp=p[i].fuel;
                p[i].fuel=p[j].fuel;
                p[j].fuel=temp;
            }
        }
    }
}
int minstp(petrolpump p[100],int n,int d,int sp)
{
    int ctr=0,cd=0;
    srt(p,n);
    priority_queue<int> maxhp;
    for(int i=0;i<n;i++)
    {
        sp=sp-(p[i].dis-cd);
        cd=p[i].dis;
        maxhp.push(p[i].fuel);
        //cout<<"    cd="<<cd<<"    sp="<<sp<<endl;     //to show current distance(cd) and current petrol(sp) remove 1st comment tag use for debugging
        if(sp<=0)
        {
            sp+=maxhp.top();
            maxhp.pop();
            ctr++;
        }
    }
    if((d-cd)>sp)
    {
        ctr++;
    }
    return ctr;
}
int main()
{
    petrolpump p[100];
    int n,i,numofstp,d,sp;
    cout<<"Enter the distance of truck from city:";
    cin>>d;
    cout<<"Enter The no. of petrol pumps:";
    cin>>n;
    cout<<"Enter The starting fuel:";
    cin>>sp;
    cout<<"Enter the distance from truck and fuel available in them:";
    for(i=0;i<n;i++)
    {
        cin>>p[i].dis;
        cin>>p[i].fuel;
    }
    numofstp=minstp(p,n,d,sp);
    cout<<"The Minimum Number of Stop to be Made is:"<<numofstp;
    return 0;
}
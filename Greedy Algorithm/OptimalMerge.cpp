#include<bits/stdc++.h>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
int lwercst(vector<int> sz,int n)
{
    priority_queue<int,vector<int>,greater<int>> minhp;
    for(int i=0;i<n;i++)
    {
        minhp.push(sz[i]);
    }
    int mincst=0;
    while(minhp.size()>1)
    {
        int a=minhp.top();
        minhp.pop();
        int b=minhp.top();
        minhp.pop();
        mincst+=a+b;
        minhp.push(a+b);
    }
    return mincst;
}
int main()
{
    vector<int> sz;
    int n,min;
    cout<<"Enter No. of Lists:";
    cin>>n;
    cout<<"Enter Sizes of lsit:";
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        sz.push_back(d);
    }
    sort(sz.begin(),sz.end());
    min=lwercst(sz,n);
    cout<<"The Min Cost of merging is:"<<min;
    return 0;
}
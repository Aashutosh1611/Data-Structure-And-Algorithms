#include<bits/stdc++.h>
#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    long long mx=0,mn=0;
    int n,i;
    cout<<"Enter No. Of Elements:";
    cin>>n;
    int ar[1000];
    cout<<"Enter Elements:";
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    for(i=0;i<n/2;i++)
    {
        mx+=(ar[i+n/2]-ar[i]);
        mn+=(ar[2*i+1]-ar[2*i]);
    }
    cout<<"Maximum Diff:"<<mx<<endl<<"Minimum Diff:"<<mn;
    return 0;
}
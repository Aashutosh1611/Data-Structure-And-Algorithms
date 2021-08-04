#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
bool iscycle(int src,vector<int> gr[100],vector<bool> &vis,int prnt)
{
    vis[src]=1;
    for(auto i:gr[src])
    {
        if(i!=prnt)
        {
            if(vis[i])
                return 1;
            if(!vis[i] && iscycle(i,gr,vis,src))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> gr[100];
    int n,e,i;
    cout<<"Enter No. of Nodes:";
    cin>>n;
    cout<<"Enter No. of Edges:";
    cin>>e;
    cout<<"Enter Edges:";
    int x,y;
    vector<bool> vis(n,0);
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for(i=0;i<n;i++)
    {
        if(!vis[i] && iscycle(i,gr,vis,-1))
        {
            cout<<"Cycle Detected";
            break;
        }
    }
    return 0;
}
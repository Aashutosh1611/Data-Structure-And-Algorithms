#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> gr[100];
    int n,i,e,j;
    cout<<"Enter No. of Nodes:";
    cin>>n;
    cout<<"Enter No. of Edges:";
    cin>>e;
    cout<<"Enter Edges:";
    int x,y;
    vector<int> indeg(n,0);       //Calculating Indegree of that node
    queue<int> q;
    for(i=0;i<e;i++)     //Directed Graph
    {
        cin>>x>>y;
        gr[x].push_back(y);
        indeg[y]++;
    }
    for(i=0;i<=n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int x;
        x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto it:gr[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
                q.push(it);
        }
    }
    return 0;
}
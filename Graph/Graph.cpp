#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
bool v[100];
vector<int> gr[100];
void DFS(int n)
{
    v[n]=1;
    cout<<n<<" ";
    vector<int>:: iterator i;
    for(i=gr[n].begin();i!=gr[n].end();i++)
    {
        if(!v[*i])
        {
            DFS(*i);
        }
    }
}
int main()
{
    int admat[100][100];
    int n,i,e,j;
    cout<<"Enter No. of Nodes:";
    cin>>n;
    cout<<"Enter No. of Edges:";
    cin>>e;
    cout<<"Enter Edges:";
    int x,y;
    /*for(i=0;i<n+1;i++)
        for(j=0;j<n+1;j++)
            admat[i][j]=0;
    for(i=0;i<e;i++)            //Adjacent Matrix
    {
        cin>>x>>y;
        admat[x][y]=1;
        admat[y][x]=1;
    }
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            cout<<admat[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(i=0;i<e;i++)  //Adjacent List
    {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for(i=0;i<n+1;i++)
    {
        cout<<"Root->"<<i;
        for(auto x:gr[i])
        {
            cout<<"-->"<<x;
        }
        cout<<endl;
    }

    cout<<endl;
    //Breadth First Search
    cout<<"BFS"<<"\n"<<endl;
    bool vis[1000];
    for(i=0;i<n;i++)
        vis[i]=0;
    queue<int> qu;
    qu.push(1);
    vis[1]=1;
    while(!qu.empty())
    {
        int node=qu.front();
        qu.pop();
        cout<<node<<" ";
        vector<int> :: iterator it;
        for(it=gr[node].begin();it!=gr[node].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=1;
                qu.push(*it);
            }
        }
    }
    cout<<endl;

    //Depth First Search
    cout<<"DFS"<<"\n";
    cout<<endl;
    for(i=0;i<n;i++)
        v[i]=0;
    DFS(1);
    return 0;
}
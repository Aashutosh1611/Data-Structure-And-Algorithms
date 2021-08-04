#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> gr[100];
    vector<int> stc;
    vector<int> :: iterator it;
    int n,i,e,j;
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
        gr[x].push_back(y);     //1-->2  2-->3   3-->4      4-->1
        /*stc.push_back(x);       //1      2       3          4 
        it=find(stc.begin(),stc.end(),y);//2    3   4       1
        if(it!=stc.end())
        {
            cout<<"Cycle Detected";
        }*/
    }
    
    for(i=1;i<n+1;i++)                      //1-->2                   0-->1->2            0-->1->2
    {                                       //2-->3                   1-->2               1-->2
        stc.push_back(i);                   //3-->4                   2-->0->3            2-->3
        for(auto x:gr[i])                   //4-->1                   3-->3               3-->
        {
            it=find(stc.begin(),stc.end(),x);
            if(it!=stc.end())
            {
                cout<<"Cycle Detected";
                break;
            }
        }
    }
    
    return 0;
}
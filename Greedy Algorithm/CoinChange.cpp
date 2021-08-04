#include<bits/stdc++.h>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
int coin_change(array<int,10> denm,int amt)
{
    int min=0,ca=0;
    for(int i=0;i<10;i++)
    {
        //1st Approach
        /*if(denm[i]+ca<=amt)
        {
            while(denm[i]+ca<=amt)
            {
                min++;
                ca+=denm[i];
            }
        }*/
        //2nd Approach
        min+=amt/denm[i];
        amt-=(amt/denm[i])*denm[i];
    }
    return min;
}
int main()
{
    array<int,10> denm ={2000,500,200,100,50,20,10,5,2,1};
    int amt,min;
    cout<<"Enter The Amount:";
    cin>>amt;
    min=coin_change(denm,amt);
    cout<<"The Minimun No. Of Coins:"<<min;
    return 0;
}
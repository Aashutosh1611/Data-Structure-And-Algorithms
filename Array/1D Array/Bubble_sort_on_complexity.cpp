#include<iostream>
using namespace std;
int main()
{
    int a[10]={4,3,5,2,9,6,1,7,8,0};
    int i=0,j=0,temp;
    while(i<10)
    {
        if(a[i]<a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        j++;
        if(j==10)
        {
            j=0;
            i++;
        }
    }
    for(i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
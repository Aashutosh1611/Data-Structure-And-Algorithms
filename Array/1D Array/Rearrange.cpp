#include<iostream>
using namespace std;
void rearrange(int a[],int n)
{
    int i,j,temp,len1,len2,t,k;
    int b[100],c[100],s[1000];
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    len1=n/2;
    len2=n-len1;
    for(i=0;i<len1;i++)
        b[i]=a[i];
    for(j=len2-1;i<n && j>=0;j--,i++)
        c[j]=a[i];
    /*for(i=0;i<len1;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    for(j=0;j<len2;j++)
        cout<<c[j]<<" ";
    cout<<endl;*/
    for(i=0,j=0,k=0;i<n/2,j<len2;j++,i++)
    {
        s[k]=c[j];
        k++;
        s[k]=b[i];
        k++;
    }
    for(i=0;i<n;i++)
        cout<<s[i]<<" ";    
}
int main()
{
    int a[10000],n,i,j;
    cout<<"Enter No. of Elements:";
    cin>>n;
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    rearrange(a,n);    
}
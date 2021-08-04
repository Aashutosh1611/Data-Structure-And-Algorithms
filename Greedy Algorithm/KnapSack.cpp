#include<iostream>
using namespace std;
class objects
{
    public:
        void inwei(int d)
        {
            weight=d;
        }
        void inpro(int d)
        {
            profit=d;
        }
        void calc()
        {
            ratio=profit/weight;
        }
        void inrat(int d)
        {
            ratio=0;
            inc=1;
        }
        float retrat()
        {
            return ratio;
        }
        int retwei()
        {
            return weight;
        }
        int retpro()
        {
            return profit;
        }
        int retinc()
        {
            return inc;
        }
    private:
        int weight;
        int profit;
        float ratio;
        int inc=0;

};
int maxofobj(objects obj[],int n)
{
    int i,t;
    float max=0,temp;
    for(i=0;i<n;i++)
    {
        temp=obj[i].retrat
        if(max<temp)
        {
            max=temp;
            t=i;
        }
    }
    return t;
}
float knapsack(objects obj[],int n,float k)
{
    float sol,max;
    int i;
    while(k>0)
    {
        i=maxofobj(obj,n);
        if(obj[i].retwei<k)
        {
            k-=obj[i].retwei;
            sol+=obj[i].retpro;
            obj[i].inrat(0);
        }
        else
        {
            float temp,p;
            temp=k/obj[i].retwei;
            p=temp*obj[i].retpro;
            sol+=p;
            k=0;
        }
    }
    return sol;
}
int main()
{
    objects obj[100];
    int n,i,d;
    float sol,k;
    cout<<"Enter The Limit Of Bag:";
    cin>>k;
    cout<<"Enter The No. Of Objects";
    cin>>n;
    cout<<"Enter The Profit For Each Object";
    for(i=0;i<n;i++)
    {
        cin>>d;
        obj[i].inpro(d);
    }
    cout<<"\nEnter The Weight For Each Object";
    for(i=0;i<n;i++)
    {
        cin>>d;
        obj[i].inwei(d);
        obj[i].calc;
    }
    sol=knapsack(obj,n,k);
    for(i=0;i<n;i++)
    {
        if(obj[i].retinc==1)
        {
            cout<<obj[i].retwei<<"      ";
            cout<<obj[i].retpro<<"\n";
        }
    }
    return 0;
}
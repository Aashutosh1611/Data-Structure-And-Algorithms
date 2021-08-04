#include<iostream>
using namespace std;
class base
{
    public:
        int func1(int data)
        {
            d=data;
            d++;
            cout<<d;
            return d;
        }
        int swap();
        base()
        {
            d=0;c=0;
            cout<<"Base Constructor\n";
        }
        ~base()
        {
            cout<<"Base Destructor\n";
        }
        private:
        int d;
        char c;
        float f;
    protected:
        int a,b;
};
int base::swap()
{

}
class child: public base
{
    public:
        int func2()
        {
            a=7;
            cout<<func1(a);
            return a;
        }
        child()
        {
            cout<<"Child Constructor\n";
        }
        ~child()
        {
            cout<<"Child Destructor\n";
        }
    protected:

};
int main()
{
    int a=7,c;
    base b;
    cout<<a;
    //cout<<b.func2();
    return 0;
}
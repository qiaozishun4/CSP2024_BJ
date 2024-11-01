#include <iostream>

using namespace std;

void stick(int n)
{
    if(n<=1)
    {
        cout<<-1<<endl;
        return;
    }
    if(n>1&&n<7)
    {
        if(n==2)
            cout<<1<<endl;
        if(n==3)
            cout<<7<<endl;
        if(n==4)
            cout<<4<<endl;
        if(n==5)
            cout<<2<<endl;
        if(n==6)
            cout<<6<<endl;
        return;
    }
    int cases=n/7;
    if(n%7!=0)
    {
        cases++;
        if(n%7==1)
        {
            cout<<10;
            for(int i=0;i<cases-2;i++)
            {
                cout<<8;
            }
            cout<<endl;
            return;
        }
        else if(n%7==2)
        {
            cout<<1;
            for(int i=0;i<cases-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            return;
        }
        else if(n%7==3)
        {
            cout<<22;
            for(int i=0;i<cases-2;i++)
            {
                cout<<8;
            }
            cout<<endl;
            return;
        }
        else if(n%7==4)
        {
            cout<<20;
            for(int i=0;i<cases-2;i++)
            {
                cout<<8;
            }
            cout<<endl;
            return;
        }
        else if(n%7==5)
        {
            cout<<2;
            for(int i=0;i<cases-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            return;
        }
        else if(n%7==6)
        {
            cout<<6;
            for(int i=0;i<cases-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            return;
        }
    }
    else
    {
        for(int i=0;i<cases;i++)
        {
            cout<<8;
        }
        cout<<endl;
        return;
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        stick(n);
    }
    return 0;
}

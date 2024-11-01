#include <iostream>
using namespace std;
int n;
int T;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==3)
        {
            cout<<7<<endl;
            continue;
        }
        if(n==4)
        {
            cout<<4<<endl;
            continue;
        }
        if(n==5)
        {
            cout<<2<<endl;
            continue;
        }
        if(n==6)
        {
            cout<<6<<endl;
            continue;
        }
        int x=n%7;
        if(x==0)
        {
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        if(x==1)
        {
            cout<<10;
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<endl;
        }
        if(x==2)
        {
            cout<<1;
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        if(x==3)
        {
            cout<<23;
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<endl;
        }
        if(x==4)
        {
            cout<<20;
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<endl;
        }
        if(x==5)
        {
            cout<<2;
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        if(x==6)
        {
            cout<<6;
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
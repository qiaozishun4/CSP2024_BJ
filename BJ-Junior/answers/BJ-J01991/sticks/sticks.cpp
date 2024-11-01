#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<7)
        {
            if(n==1)
            {
                cout<<-1<<"\n";
            }
            if(n==2)
            {
                cout<<1<<"\n";
            }
            if(n==3)
            {
                cout<<7<<"\n";
            }
            if(n==4)
            {
                cout<<4<<"\n";
            }
            if(n==5)
            {
                cout<<2<<"\n";
            }
            if(n==6)
            {
                cout<<6<<"\n";
            }
        }
        else if(n%7==0)
        {
            for(int i=1; i<=n/7; n++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
        else if((n-1)%7==0)
        {
            cout<<10;
            n-=8;
            for(int i=1; i<=n/7; i++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
        else if((n-2)%7==0)
        {
            cout<<1;
            n-=2;
            for(int i=1; i<=n/7; i++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
        else if((n-3)%7==0)
        {
            cout<<22;
            n-=10;
            for(int i=1; i<=n/7; i++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
        else if((n-4)%7==0)
        {
            cout<<20;
            n-=11;
            for(int i=1; i<=n/7; i++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
        else if((n-5)%7==0)
        {
            cout<<2;
            n-=5;
            for(int i=1; i<=n/7; i++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
        else if((n-6)%7==0)
        {
            cout<<6;
            n-=6;
            for(int i=1; i<=n/7; i++)
            {
                cout<<8;
            }
            cout<<"\n";
        }
    }
}

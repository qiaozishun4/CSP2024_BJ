#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=n%7;
        if(n<2)
        {
            cout<<-1<<"\n";
            continue;
        }
        if(n<8)
        {
            if(n==2)cout<<1;
            else if(n==3)cout<<7;
            else if(n==4)cout<<4;
            else if(n==5)cout<<2;
            else if(n==6)cout<<6;
            else if(n==7)cout<<8;
            cout<<"\n";
            continue;
        }
        if(m==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(m==1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(m==2)
        {
            cout<<1;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(m==3)
        {
            cout<<22;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(m==4)
        {
            cout<<20;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(m==5)
        {
            cout<<2;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(m==6)
        {
            cout<<6;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    int n;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7 == 0)
        {
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7 == 1)
        {
            cout<<1<<0;
            for(int j=1;j<n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7 == 2)
        {
            cout<<1;
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7 == 3)
        {
            cout<<2<<0<<0;
            for(int j=2;j<n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7 == 4)
        {
            cout<<2<<0;
            for(int j=1;j<n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7 == 5)
        {
            cout<<2;
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        if(n%7 == 6)
        {
            cout<<6;
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}

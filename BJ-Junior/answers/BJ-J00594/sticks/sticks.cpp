#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int i;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<10;
            for(i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==2)
        {
            cout<<1;
            for(i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==3)
        {
            cout<<23;
            for(i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==4)
        {
            cout<<20;
            for(i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==5)
        {
            cout<<2;
            for(i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6)
        {
            cout<<6;
            for(i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}

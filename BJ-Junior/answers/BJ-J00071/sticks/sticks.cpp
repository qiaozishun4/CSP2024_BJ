#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n==3)cout<<7;
        else if(n==2)cout<<5;
        else if(n==4)cout<<4;
        else if(n==5)cout<<2;
        else if(n==6)cout<<6;
        else if(n%7==0)
        {
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        else if(n%7==1)
        {
            cout<<-1;
        }
        else if(n%7==2)
        {
            cout<<1;
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        else if(n%7==3)
        {
            cout<<22;
            for(int j=1;j<n/7;j++)
            {
                cout<<8;
            }
        }
        else if(n%7==4)
        {
            cout<<20;
            for(int j=1;j<n/7;j++)
            {
                cout<<8;
            }
        }
        else if(n%7==5)
        {
            cout<<2;
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        else
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

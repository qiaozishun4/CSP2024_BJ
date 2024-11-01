#include<bits/stdc++.h>
using namespace std;
long long t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<"\n";
            continue;
        }
        if(n%7==1)
        {
            cout<<10;
            n-=8;
        }
        else if(n%7==2)
        {
            cout<<1;
            n-=2;
        }
        else if(n%7==3)
        {
            if(n==3)
            {
                cout<<7<<"\n";
                continue;
            }
            cout<<22;
            n-=10;
        }
        else if(n%7==4)
        {
            if(n==4)
            {
                cout<<4<<"\n";
                continue;
            }
            cout<<20;
            n-=11;
        }
        else if(n%7==5)
        {
            cout<<2;
            n-=5;
        }
        else if(n%7==6)
        {
            cout<<6;
            n-=6;
        }
        while(n)
        {
            n-=7;
            cout<<8;
        }
        cout<<"\n";
    }
    return 0;
}

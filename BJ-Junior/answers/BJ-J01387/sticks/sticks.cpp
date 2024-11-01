#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll num=n/7;
        if(n%7!=0) num++;
        ll cnt=num*7-n;
        if(cnt==0) for(ll i=1;i<=num;i++) cout<<8;
        if(cnt==1)
        {
            cout<<6;
            for(ll i=2;i<=num;i++) cout<<8;
        }
        if(cnt==2)
        {
            cout<<2;
            for(ll i=2;i<=num;i++) cout<<8;
        }
        if(cnt==3)
        {
            if(n==4){cout<<4<<endl;continue;}
            cout<<20;
            for(ll i=3;i<=num;i++) cout<<8;
        }
        if(cnt==4)
        {
            if(n==3){cout<<7<<endl;continue;}
            if(n==10){cout<<78<<endl;continue;}
            cout<<200;
            for(ll i=4;i<=num;i++) cout<<8;
        }
        if(cnt==5)
        {
            cout<<1;
            for(ll i=2;i<=num;i++) cout<<8;
        }
        if(cnt==6)
        {
            if(n==1){cout<<-1<<endl;continue;}
            cout<<10;
            for(ll i=3;i<=num;i++) cout<<8;
        }
        cout<<endl;
    }
    return 0;
}

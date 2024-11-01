#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1;
            cout<<"\n";
            continue;
        }
        int l=ceil(1.0*n/7.0);
        if(7*l-n==0)
        {
            for(int i=1;i<=l;i++) cout<<8;
            cout<<"\n";
        }
        else if(7*l-n==1)
        {
            cout<<6;
            for(int i=1;i<=l-1;i++) cout<<8;
            cout<<"\n";
        }
        else if(7*l-n==2)
        {
            cout<<2;
            for(int i=1;i<=l-1;i++) cout<<8;
            cout<<"\n";
        }
        else if(7*l-n==3)
        {
            if(l==1)cout<<4;
            else cout<<20;
            for(int i=1;i<=l-2;i++) cout<<8;
            cout<<"\n";
        }
        else if(7*l-n==4)
        {
            if(l==1) cout<<7;
            else if(l==2)cout<<22;
            else cout<<200;
            for(int i=1;i<=l-3;i++) cout<<8;
            cout<<"\n";
        }
        else if(7*l-n==5)
        {
            cout<<1;
            for(int i=1;i<=l-1;i++) cout<<8;
            cout<<"\n";
        }
        else
        {
            cout<<10;
            for(int i=1;i<=l-2;i++) cout<<8;
            cout<<"\n";
        }
    }
    return 0;
}

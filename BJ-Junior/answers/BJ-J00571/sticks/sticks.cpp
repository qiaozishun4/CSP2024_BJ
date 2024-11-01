#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
    freopen("sticks.in","r",stdin);freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int n;cin>>n;
        if(n%7==0){for(int i=1;i<=n/7;i++) cout<<8;cout<<endl;}
        else if(n%7==1)
        {
            if(n-1){cout<<10;for(int i=1;i<=n/7-1;i++) cout<<8;}
            else cout<<-1;
            cout<<endl;
        }
        else if(n%7==2){cout<<1;for(int i=1;i<=n/7;i++) cout<<8;cout<<endl;}
        else if(n%7==3)
        {
            if(n==3) cout<<7;
            else if(n==10) cout<<22;
            else{cout<<200;for(int i=1;i<=n/7-2;i++) cout<<8;}
            cout<<endl;
        }
        else if(n%7==4)
        {
            if(n==4) cout<<4;
            else{cout<<20;for(int i=1;i<=n/7-1;i++) cout<<8;}
            cout<<endl;
        }
        else if(n%7==5){cout<<2;for(int i=1;i<=n/7;i++) cout<<8;cout<<endl;}
        else{cout<<6;for(int i=1;i<=n/7;i++) cout<<8;cout<<endl;}
    }
    return 0;
}
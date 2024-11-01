#include<bits/stdc++.h>
using namespace std;
long long T,n,x,k;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        x=n%7;
        k=n/7;
        if(x==0)
        {
            for(long long i=1;i<=k;i++) cout<<8;
            cout<<endl;
        }
        else if(x==1)
        {
            if(k==0) cout<<-1;
            else
            {
                cout<<10;
                for(long long i=1;i<=k-1;i++) cout<<8;
            }
            cout<<endl;
        }
        else if(x==2)
        {
            cout<<1;
            for(long long i=1;i<=k;i++) cout<<8;
            cout<<endl;
        }
        else if(x==3)
        {
            if(k==0) cout<<7;
            else if(k==1) cout<<22;
            else
            {
                cout<<200;
                for(long long i=1;i<=k-2;i++) cout<<8;
            }
            cout<<endl;
        }
        else if(x==4)
        {
            if(k==0) cout<<4;
            else
            {
                cout<<20;
                for(long long i=1;i<=k-1;i++) cout<<8;
            }
            cout<<endl;
        }
        else if(x==5)
        {
            cout<<2;
            for(long long i=1;i<=k;i++) cout<<8;
            cout<<endl;
        }
        else
        {
            cout<<6;
            for(long long i=1;i<=k;i++) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}

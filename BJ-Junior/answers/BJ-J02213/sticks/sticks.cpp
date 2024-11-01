#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<2) {cout<<-1<<'\n';continue;}
        if(n%7==0)
        {
            while(n!=0)
            {
                cout<<8;
                n-=7;
            }
        }
        if(n%7==1)
        {
            cout<<10;
            while(n-8!=0)
            {
                cout<<8;
                n-=7;
            }
        }
        if(n%7==2)
        {
            cout<<1;
            while(n-2!=0)
            {
                cout<<8;
                n-=7;
            }
        }
        if(n%7==3)
        {
            if(n==3) cout<<7;
            else if(n==10) cout<<22;
            else cout<<200;
            while(n-17>0)
            {
                cout<<8;
                n-=7;
            }
        }
        if(n%7==4)
        {
            if(n==4) cout<<4;
            else cout<<20;
            while(n-11>0)
            {
                cout<<8;
                n-=7;
            }
        }
        if(n%7==5)
        {
            cout<<2;
            while(n-5>0)
            {
                cout<<8;
                n-=7;
            }
        }
        if(n%7==6)
        {
            cout<<6;
            while(n-6>0)
            {
                cout<<8;
                n-=7;
            }
        }
        cout<<'\n';
    }
    return 0;
}

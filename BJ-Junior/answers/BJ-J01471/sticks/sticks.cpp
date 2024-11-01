#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<14)
        {
            if(n==1)
            {
                cout<<-1;
            }
            if(n==2)
            {
                cout<<1;
            }
            if(n==3)
            {
                cout<<7;
            }
            if(n==4)
            {
                cout<<4;
            }
            if(n==5)
            {
                cout<<2;
            }
            if(n==6)
            {
                cout<<6;
            }
            if(n==7)
            {
                cout<<8;
            }
            if(n==8)
            {
                cout<<16;
            }
            if(n==9)
            {
                cout<<67;
            }
            if(n==10)
            {
                cout<<22;
            }
            if(n==11)
            {
                cout<<26;
            }
            if(n==12)
            {
                cout<<27;
            }
            if(n==13)
            {
                cout<<68;
            }
            cout<<endl;
            continue;//1=2,7=3,4=4,2=5,6=6,0=6,8=7,16=8,67=9,22=10
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }
        if(n%7==1)
        {
            cout<<16;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
        }
        if(n%7==2)
        {
            cout<<1;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }
        if(n%7==3)
        {
            cout<<10;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }
        if(n%7==4)
        {
            cout<<20;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
        }
        if(n%7==5)
        {
            cout<<2;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }
        if(n%7==6)
        {
            cout<<6;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}

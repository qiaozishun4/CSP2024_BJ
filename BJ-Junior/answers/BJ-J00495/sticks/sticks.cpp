#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(n>=14)
        {
            if(n%7==0)
            {
                int cnt=n/7;
                for(int i=1;i<=cnt;++i)
                {
                    cout<<8;
                }
            }
            else if(n%7==1)
            {
                cout<<1;
                cout<<0;
                int cnt=n/7;
                for(int i=1;i<=cnt-1;++i)
                {
                    cout<<8;
                }
            }
            else if(n%7==2)
            {
                cout<<7;
                cout<<0;
                int cnt=n/7;
                for(int i=1;i<=cnt-1;++i)
                {
                    cout<<8;
                }
            }
            else if(n%7==3)
            {
                cout<<4;
                cout<<0;
                int cnt=n/7;
                for(int i=1;i<=cnt-1;++i)
                {
                    cout<<8;
                }
            }
            else if(n%7==4)
            {
                cout<<2;
                cout<<0;
                int cnt=n/7;
                for(int i=1;i<=cnt-1;++i)
                {
                    cout<<8;
                }
            }
            else if(n%7==5)
            {
                cout<<6;
                cout<<0;
                int cnt=n/7;
                for(int i=1;i<=cnt-1;++i)
                {
                    cout<<8;
                }
            }
            else if(n%7==6)
            {
                cout<<8;
                cout<<0;
                int cnt=n/7;
                for(int i=1;i<=cnt-1;++i)
                {
                    cout<<8;
                }
            }
            cout<<endl;
        }
        else
        {

            if(n==2)
            {
                cout<<1;
            }
            else if(n==3)
            {
                cout<<7;
            }
            else if(n==4)
            {
                cout<<4;
            }
            else if(n==5)
            {
                cout<<2;
            }
            else if(n==6)
            {
                cout<<6;
            }
            else if(n==7)
            {
                cout<<8;
            }
            else if(n==8)
            {
                cout<<16;
            }
            else if(n==9)
            {
                cout<<18;
            }
            else if(n==10)
            {
                cout<<22;
            }
            else if(n==11)
            {
                cout<<26;
            }
            else if(n==12)
            {
                cout<<28;
            }
            else if(n==13)
            {
                cout<<68;
            }
        }
    }
    return 0;
}

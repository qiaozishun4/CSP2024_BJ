#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int cost[]={6,2,5,5,4,5,6,3,7,6};
int num[]={-1,-1,1,7,4,2,6,8,10,18,23,20,28,68,88,108,188,200,208,288,688};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n<=20)
        {
            cout<<num[n]<<endl;
            continue;
        }
        if(n>=100 && n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<"10";
            for(int i=1;i<=n/7-1;i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n>=100 && n%7==2)
        {
            cout<<"1";
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n>=100 && n%7==3)
        {
            cout<<200;
            for(int i=1;i<=n/7-2;i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n>=100 && n%7-3>0)
        {
            if(n%7==4) cout<<4;
            if(n%7==5) cout<<2;
            if(n%7==6) cout<<6;
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n<100)
        {
            if(n%7==0)
            {
                for(int i=1;i<=n/7;i++) cout<<8;
                cout<<endl;
                continue;
            }
            if(n%7==2)
            {
                cout<<1;
                for(int i=1;i<=n/7;i++) cout<<8;
                cout<<endl;
                continue;
            }
            if(n%7==3)
            {
                cout<<200;
                for(int i=1;i<=n/7-2;i++) cout<<8;
                cout<<endl;
                continue;
            }
            if(n%7==4)
            {
                cout<<20;
                for(int i=1;i<=n/7-1;i++) cout<<8;
                cout<<endl;
                continue;
            }
            if(n%7==5)
            {
                cout<<2;
                for(int i=1;i<=n/7;i++) cout<<8;
                cout<<endl;
                continue;
            }
            if(n%7==6)
            {
                cout<<6;
                for(int i=1;i<=n/7;i++) cout<<8;
                cout<<endl;
                continue;
            }
        }
    }
    return 0;
}

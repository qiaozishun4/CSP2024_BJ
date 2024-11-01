#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        int s=m/7;
        if(m==0||m==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(m==3)
        {
            cout<<7<<endl;
            continue;
        }
        if(m==4)
        {
            cout<<4<<endl;
            continue;
        }
        if(m==10)
        {
            cout<<22<<endl;
            continue;
        }
        if(m%7==0)
            for(int j=1;j<=s;j++)
            cout<<8;
        if(m%7==1)
        {
            cout<<10;
            for(int i=1;i<s;i++)
                cout<<8;
        }
        if(m%7==2)
        {
            cout<<1;
            for(int i=1;i<=s;i++)
                cout<<8;
        }
        if(m%7==3)
        {
            cout<<200;
            for(int i=1;i<s-1;i++)
                cout<<8;
        }
        if(m%7==4)
        {
            cout<<20;
            for(int i=1;i<s;i++)
                cout<<8;
        }
        if(m%7==5)
        {
            cout<<2;
            for(int i=1;i<=s;i++)
                cout<<8;
        }
        if(m%7==6)
        {
            cout<<6;
            for(int i=1;i<=s;i++)
                cout<<8;
        }
        cout<<endl;
    }
    return 0;
}

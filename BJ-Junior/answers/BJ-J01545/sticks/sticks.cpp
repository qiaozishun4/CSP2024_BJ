#include<bits/stdc++.h>
using namespace std;
void calc()
{
    int n;
    cin>>n;
    int k=n/7;
    if(n%7==0)
    {
        for(int i=1;i<=k;i++)
        {
            cout<<8;
        }
        cout<<endl;
        return;
    }
    if(n%7==1)
    {
        if(k==0)
        {
            cout<<-1<<endl;
            return;
        }
        cout<<10;
        for(int i=1;i<k;i++)
        {
            cout<<8;
        }
        cout<<endl;
        return;
    }
    if(n%7==2)
    {
        cout<<1;
        for(int i=1;i<=k;i++) cout<<8;
        cout<<endl;
        return;
    }if(n%7==3)
    {
        if(k==0)
        {
            cout<<7<<endl;
            return;
        }if(k==1)
        {
            cout<<22<<endl;
            return;
        }
        cout<<200;
        for(int i=1;i<k-1;i++)
        {
            cout<<8;
        }
        cout<<endl;
        return;
    }if(n%7==4)
    {
        if(k==0)
        {
            cout<<4<<endl;
            return;
        }
        cout<<20;
        for(int i=1;i<k;i++)
        {
            cout<<8;
        }
        cout<<endl;
        return;
    }if(n%7==5)
    {
        cout<<2;
        for(int i=1;i<=k;i++)
        {
            cout<<8;
        }
        cout<<endl;
    }if(n%7==6)
    {
        cout<<6;
        for(int i=1;i<=k;i++){
            cout<<8;
        }
        cout<<endl;
        return;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        calc();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int q;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int n,s,t;
        cin>>n;
        if(n<=1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==3)
        {
            cout<<7<<endl;
            continue;
        }
        if(n==4)
        {
            cout<<4<<endl;
            continue;
        }
        if(n==5)
        {
            cout<<3<<endl;
            continue;
        }
        if(n==6)
        {
            cout<<6<<endl;
            continue;
        }
        if(n==7)
        {
            cout<<8<<endl;
            continue;
        }
        s=n%7+7;
        t=n/7-1;
        if(s==7)
        {
            cout<<8;
        }
        else if(s==8)
        {
            cout<<10;
        }
        else if(s==9)
        {
            cout<<18;
        }
        else if(s==10)
        {
            cout<<22;
        }
        else if(s==11)
        {
            cout<<20;
        }
        else if(s==12)
        {
            cout<<28;
        }
        else
        {
            cout<<68;
        }
        for(int i=1;i<=t;i++)
        {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}

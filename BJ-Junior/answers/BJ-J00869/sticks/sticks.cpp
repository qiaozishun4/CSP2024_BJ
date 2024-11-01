#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    int n;
    cin>>n;
    int q=n;
    if(q==1)
    {
        cout<<-1;
        q=0;
    }
    else if(q==6)
    {
        cout<<6;
        q=0;
    }
   while(q>0)
    {
        if(q==10)
        {
            cout<<40;
            q-=10;
        }
        if(q==8)
        {
            cout<<44;
            q-=8;
        }
        else if(q>7)
        {
            cout<<8;
            q-=7;
        }
        else if(q==6)
        {
            cout<<0;
            q-=6;
        }
        else if(q==5)
        {
            cout<<3;
            q-=5;
        }
        else if(q==4)
        {
            cout<<4;
            q-=4;
        }
        else if(q==3)
        {
            cout<<7;
            q-=3;
        }
        else if(q==2)
        {
            cout<<1;
            q-=2;
        }
    }
    }
    return 0;
}

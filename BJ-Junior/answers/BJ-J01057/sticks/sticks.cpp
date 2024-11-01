#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x=n/7;
        int y=n%7;
        if(y==2)
        {
            cout<<1;
        }
        if(y==3)
        {
            cout<<7;
        }
        if(y==4)
        {
            cout<<4;
        }
        if(y==5)
        {

            cout<<2;
        }
        if(y==6)
        {
            cout<<6;
        }
        if(y==1&&x==0)
        {
            cout<<-1;
            continue;
        }
        if(y==1)
        {
            cout<<10;
            x--;
        }
        for(int i=1;i<=x;i++)
        {
            cout<<8;
        }
    }
}

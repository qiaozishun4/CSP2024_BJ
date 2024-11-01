#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n<=1)
        {
            cout<<-1;
            n=0;
        }
        if(n==4)
        {
            cout<<n;
            n=0;
        }
        if(n==3)
        {
            cout<<7;
            n=0;
        }
        if(n%7==1)
        {
            cout<<10;
            n-=8;
        }
        if(n%7==2)
        {
            cout<<1;
            n-=2;
        }
        if(n%7==3)
        {
            cout<<22;
            n-=10;
        }
        if(n%7==4)
        {
            cout<<20;
            n-=11;
        }
        if(n%7==5)
        {
            cout<<2;
            n-=5;
        }
        if(n%7==6)
        {
            cout<<6;
            n-=6;
        }
        while(n!=0)
        {
            n-=7;
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
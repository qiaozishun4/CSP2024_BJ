#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        if(a==2)
        {
            cout<<1;
        }
        else if(a==5)
        {
            cout<<2;
        }
        else if(a==4)
        {
            cout<<4;
        }
        else if(a==3)
        {
            cout<<7;
        }
        else if(a==7)
        {
            cout<<8;
        }
        else{
            cout<<-1;
        }
    }
    return 0
}
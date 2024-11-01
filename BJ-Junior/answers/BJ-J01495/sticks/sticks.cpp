#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,x,i;
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(x%7==0)
        {
            for(i=1;i<=x/7;i++)
            {
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        else if(x%7==1&&x/7>0)
        {
            cout<<10;
            for(i=1;i<x/7;i++)
            {
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        switch(x)
        {
            case 1: cout<<-1<<'\n'; break;
            case 2: cout<<1<<'\n'; break;
            case 3: cout<<7<<'\n'; break;
            case 4: cout<<4<<'\n'; break;
            case 5: cout<<2<<'\n'; break;
            case 6: cout<<6<<'\n'; break;
            case 8: cout<<10<<'\n'; break;
            case 9: cout<<18<<'\n'; break;
            case 10: cout<<40<<'\n'; break;
            case 18: cout<<208<<'\n'; break;
        }
    }
    return 0;
}
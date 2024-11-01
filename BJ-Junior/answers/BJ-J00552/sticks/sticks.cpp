#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            cout<<"-1\n";
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(n%7==2)
        {
            cout<<1;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(n%7==3)
        {
            if(n==3)
            {
                cout<<"7\n";
            }
            else if(n==10)
            {
                cout<<"22\n";
            }
            else
            {
                cout<<200;
                for(int i=1;i<=n/7-2;i++)
                {
                    cout<<8;
                }
                cout<<"\n";
            }
            continue;
        }
        else if(n%7==4)
        {
            if(n==4)
            {
                cout<<"4\n";
            }
            else
            {
                cout<<20;
                for(int i=1;i<=n/7-1;i++)
                {
                    cout<<8;
                }
                cout<<"\n";
            }
            continue;
        }
        else if(n%7==5)
        {
            cout<<2;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(n%7==6)
        {
            cout<<6;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        //bool flag=0;
        //for(ll i=1;i<=100000000;i++)
        //{
        //    if(check(i,n))
        //    {
        //        flag=1;
        //        cout<<i<<",";
        //        break;
        //    }
        //}
        //if(!flag)
        //{
        //    cout<<"-1,";
        //}
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%7==0)
        {
            n/=7;
            for(int i=1;i<=n;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1)
        {
            if(n>7)
            {
                cout<<10;
                n-=8;
                n/=7;
                for(int i=1;i<=n;i++)
                {
                    cout<<8;
                }
                cout<<endl;
            }
            else
                cout<<-1<<endl;
        }
        else if(n%7==2)
        {
            cout<<1;
            n-=2;
            n/=7;
            for(int i=1;i<=n;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==3)
        {
            if(n>7)
            {
                cout<<22;
                n-=10;
                n/=7;
                for(int i=1;i<=n;i++)
                {
                    cout<<8;
                }
                cout<<endl;
            }
            else
                cout<<7<<endl;
        }
        else if(n%7==4)
        {
            if(n>7)
            {
                cout<<20;
                n-=11;
                n/=7;
                for(int i=1;i<=n;i++)
                {
                    cout<<8;
                }
                cout<<endl;
            }
            else
                cout<<4<<endl;
        }
        else if(n%7==5)
        {
            cout<<2;
            n-=5;
            n/=7;
            for(int i=1;i<=n;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==6)
        {
            cout<<6;
            n-=6;
            n/=7;
            for(int i=1;i<=n;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}

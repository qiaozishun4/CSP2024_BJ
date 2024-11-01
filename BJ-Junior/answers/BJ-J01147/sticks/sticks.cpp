#include<bits/stdc++.h>
using namespace std;

long long T,n;
long long ans[100010];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long i;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"-1"<<endl;
            continue ;
        }
        if(n%7==0)
        {
            n/=7;
            for(long long j=1;j<=n;j++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            n--;
            n/=7;
            n--;
            cout<<"10";
            for(int i=1;i<=n;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==2)
        {
            n=n-2;
            n/=7;
            cout<<'1';
            for(int i=1;i<=n;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==3)
        {
            n=n-3;
            n/=7;
            cout<<'7';
            for(int i=1;i<=n;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==4)
        {
            n=n-4;
            n/=7;
            n--;
            cout<<"20";
            for(int i=1;i<=n;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==5)
        {
            n=n-5;
            n/=7;
            cout<<'2';
            for(int i=1;i<=n;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==6)
        {
            n=n-6;
            n/=7;
            cout<<'6';
            for(int i=1;i<=n;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}

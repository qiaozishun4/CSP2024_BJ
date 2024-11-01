#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<'\n';
            continue;
        }
        if(n%7==1)
        {
            for(int j=1;j<=n/7;j++)
            {
                if(j==1)
                {
                    cout<<10;
                }
                else
                {
                    cout<<8;
                }
            }
        }
        else if(n%7==0)
        {
            for(int j=1;j<=n/7;j++)
            {
                cout<<8;
            }
        }
        else if(n%6==0)
        {
            for(int j=1;j<=n/6;j++)
            {
                cout<<6;
            }
        }
        else if(n%5==0)
        {
            for(int j=1;j<=n/5;j++)
            {
                cout<<2;
            }
        }
        else if(n%4==0)
        {
            for(int j=1;j<=n/4;j++)
            {
                cout<<4;
            }
        }
        else if(n==3)
        {
            for(int j=1;j<=n/3;j++)
            {
                cout<<7;
            }
        }
        else if(n==2)
        {
            for(int j=1;j<=n/2;j++)
            {
                cout<<1;
            }
        }
        cout<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

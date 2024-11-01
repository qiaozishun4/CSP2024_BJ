#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        if(n>=7)
        {
            if(n%7==0)
            {
                for(int i=1;i<=n/7;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
            if(n%7==1)
            {
                cout <<1 <<0;
                for(int i=1;i<=n/7-1;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
            if(n%7==2)
            {
                cout <<1;
                for(int i=1;i<=n/7;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
            if(n%7==3)
            {
                cout <<2 <<3;
                for(int i=1;i<=n/7-1;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
            if(n%7==4)
            {
                cout <<2 <<0;
                for(int i=1;i<=n/7-1;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
            if(n%7==5)
            {
                cout <<2;
                for(int i=1;i<=n/7;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
            if(n%7==6)
            {
                cout << 6;
                for(int i=1;i<=n/7;i++)
                    cout <<8;
                cout <<"\n";
                continue;
            }
        }
        else
        {
            if(n==1)
            {
                cout <<-1 <<"\n";
                continue;
            }
            if(n==2)
            {
                cout <<1 <<"\n";
                continue;
            }
            if(n==3)
            {
                cout <<7 <<"\n";
                continue;
            }
            if(n==4)
            {
                cout <<4 <<"\n";
                continue;
            }
            if(n==5)
            {
                cout <<5 <<"\n";
                continue;
            }
            if(n==6)
            {
                cout <<6 <<"\n";
                continue;
            }
        }
    }
}

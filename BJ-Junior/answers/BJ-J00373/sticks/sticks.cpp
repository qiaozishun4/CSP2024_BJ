#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t;
    cin >> t;
    for (int i=1;i<=t;i++)
    {
    long long n;
    cin >>n;
    if (n%7==0)
    {

        for (int i=1;i<=n/7;i++)
        {

            cout << 8 ;
        }
    }
    if (n%7==6)
    {
        cout << 6;
        for (int i=1;i<=n/7;i++)
        {

            cout << 8;
        }
    }
    if (n%7==5)
    {
        cout << 2;
        for (int i=1;i<=n/7;i++)
        {
            cout << 8;
        }
    }
    if (n%7==4 &&n!=4)
    {
        cout <<20;
        for (int i=2;i<=n/7;i++)
        {
            cout <<8;
        }
    }
    if (n==4)cout << 4;
    if (n%7==3 && n!=3 && n!=10)
    {
        cout <<200;
        for (int i=3;i<=n/7;i++)
        {
            cout <<8;
        }
    }
    if (n==3)cout << 7;
    if (n==10)cout << 22;
    if (n%7==2)
    {
        cout <<1;
        for (int i=1;i<=n/7;i++)
        {
            cout <<8;
        }
    }
    if (n%7==1 && n!=1)
    {
        cout <<10;
        for (int i=2;i<=n/7;i++)
        {
            cout <<8;
        }
    }
    if (n==1)cout << -1;
    cout << endl;
    }
    return 0;
}

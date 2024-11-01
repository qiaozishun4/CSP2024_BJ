#include<bits/stdc++.h>
#define int long long
using namespace std;
void calc()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return ;
    }
    if (n == 6)
    {
        cout << 6 << endl;
        return ;
    }
    if (n == 4)
    {
        cout << 4 << endl;
        return ;
    }
    if (n == 3)
    {
        cout << 7 << endl;
        return ;
    }
    if (n % 7 == 0)
    {
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    else if (n % 7 == 1)
    {
        cout << 10;
        n -= 8;
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    else if (n % 7 == 2)
    {
        cout << 1;
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    else if (n % 7 == 3)
    {
        cout << 25;
        n -= 5 + 5;
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    else if (n % 7 == 4)
    {
        cout << 20;
        n -= 5 + 6;
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    else if (n % 7 == 5)
    {
        cout << 2;
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    else if (n % 7 == 6)
    {
        cout << 80;
        n -= 7 + 6;
        for (int i = 1 ; i <= n / 7 ; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
}
signed main()
{

    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);

//    cout << 100000 / 7 << endl;
    int t;
    cin >> t;
    while (t--)
    {
        calc();
    }
    return 0;
}


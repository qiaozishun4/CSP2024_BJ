#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << -1;
            continue;
        }
        int numof8 = n / 7;
        int s = n % 7;
        if(s == 0)
        {
            for(int j = 0; j < numof8; ++j)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(s == 1)
        {
            cout << 10;
            for(int j = 1; j < numof8; ++j)
            {
                cout << 8;
            }
            cout << endl;
        }
        if(s == 2)
        {
            cout << 1;
            for(int j = 0; j < numof8; ++j)
            {
                cout << 8;
            }
            continue;
        }
        if(s == 3)
        {
            cout << 7;
            for(int j = 0; j < numof8; ++j)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(s == 4)
        {
            cout << 4;
            for(int j = 0; j < numof8; ++j)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(s == 5)
        {
            cout << 2;
            for(int j = 0; j < numof8; ++j)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(s == 6)
        {
            cout << 6;
            for(int j = 0; j < numof8; ++j)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
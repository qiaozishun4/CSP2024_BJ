#include<bits/stdc++.h>
using namespace std;
const int up[10] = {7, 6, 6, 6, 5, 5, 5, 4, 3, 2}, upn[10] = {8, 0, 6, 9, 2, 3, 5, 4, 7, 1};
int T, n, nums[50010];
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n <= 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n % 7 == 1)
        {
            cout << "10";
            n -= 8;
        }
        if (n % 7 == 2)
        {
            if (n == 2)
            {
                cout << '1';
                n -= 2;
            }
            else
            {
                cout << "42";
                n -= 9;
            }
        }
        if (n % 7 == 3)
        {
            if (n == 3)
            {
                cout << '7';
                n -= 3;
            }
            else
            {
                cout << "40";
                n -= 10;
            }
        }
        if (n % 7 == 4)
        {
            if (n == 4)
            {
                cout << '4';
                n -= 4;
            }
            else
            {
                cout << "20";
                n -= 11;
            }
        }
        if (n % 7 == 5)
        {
            if (n == 5)
            {
                cout << '2';
                n -= 5;
            }
            else
            {
                cout << "60";
                n -= 12;
            }
        }
        if (n % 7 == 6)
        {
            cout << '6';
            n -= 6;
        }
        while (n)
        {
            cout << '8';
            n -= 7;
        }
        cout << endl;
    }
    return 0;
}

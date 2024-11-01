#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        if (n % 7 == 0)
        {
            for (int i = 0; i < n / 7; i++)
                cout << 8;
            cout << '\n';
        }
        else if ((n - 1) % 7 == 0)
        {
            cout << 10;
            for (int i = 0; i < (n - 1) / 7 - 1; i++)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}

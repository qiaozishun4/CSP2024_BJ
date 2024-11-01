#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("sticks.in", "r", stdin);
    freopen ("sticks.out", "w", stdout);
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        if (n < 7)
        {
            if (n == 1) cout << -1;
            if (n == 2) cout << 1;
            if (n == 3) cout << 7;
            if (n == 4) cout << 4;
            if (n == 5) cout << 2;
            if (n == 6) cout << 6;
        }
        else
        {
            int k = n / 7, p = n % 7;
            cout << k << endl;
            if (p == 0)
            {
                for (int i = 1; i <= k; i++) cout << 8;
            }
            if (p == 1)
            {
                k--; cout << 10;
                for (int i = 1; i <= k; i++) cout << 8;
            }
            if (p == 2)
            {
                cout << 1;
                for (int i = 1; i <= k; i++) cout << 8; 
            }
            if (p == 3)
            {
                k--; cout << 22;
                for (int i = 1; i <= k; i++) cout << 8;
            }
            if (p == 4)
            {
                k--; cout << 20;
                for (int i = 1; i <= k; i++) cout << 8;
            }
            if (p == 5)
            {
                cout << 2;
                for (int i = 1; i <= k; i++) cout << 8;
            }
            if (p == 6)
            {
                cout << 6;
                for (int i = 1; i <= k; i++) cout << 8;
            }
        }
        cout << endl;
    }
    return 0;
}
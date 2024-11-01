#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T, n;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
        }
        else
        {
            for (int i = 1; i < n / 7; i++)
            {
                cout << 8;
            }
            cout << "01";
        }
        cout << endl;
    }
    return 0;
}

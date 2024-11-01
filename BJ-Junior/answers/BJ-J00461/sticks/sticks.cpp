#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = n % 7;
        if (m == 0)
        {
            for (int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
        if (m == 1)
        {
            cout << 16;
            for (int i = 1; i < n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
    }
    return 0;
}

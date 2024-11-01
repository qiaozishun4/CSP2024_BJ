#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[8] = {-1, -1, 1, 7, 4, 2, 6, 8};
int b[7] = {8, 10, 18, 22, 20, 28, 68};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n <= 7)
        {
            cout << a[n] << endl;
            continue;
        }
        int dl = n / 7 - 1;
        cout << b[n % 7];
        for (int i = 1; i <= dl; i++) cout << "8";
        cout << endl;
    }

    return 0;
}

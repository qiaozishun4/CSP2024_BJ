#pragma GCCoptimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;

int t, n, num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int c114514 = 1 ; c114514 <= t ; c114514++)
    {
        cin >> n;
        if (n % 7 == 0)
        {
            n /= 7;
            for (int i = 1 ; i <= n ; i++)
            {
                cout << 8;
            }
        }
        else if (n % 7 == 1)
        {
            n = (n-1)/7;
            cout << 10;
            for (int i = 2 ; i <= n ; i++)
            {
                cout << 8;
            }
        }
        cout << "\n";
    }
    cout << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t, n, w;
const int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int b[8] = {0, 0, 1, 7, 4, 2, 6, 8};
string s;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        s = "";
        cin >> n;
        if (n < 2) {cout << "-1\n"; continue;}
        w = ceil(n / 7.0);
        for (int i = 1; i < w; i++)
        {
            for (int num = 0; num < 10; num++)
            {
                if (i == 1 && num == 0) continue;
                if (n - a[num] <= 7 * (w - i) && n - a[num] >= 2)
                {
                    s += '0' + num;
                    n -= a[num];
                    break;
                }
            }
        }
        if (n == 6)
        {
            if (w == 1)
                s += '6';
            else
                s += '0';
        }
        else
            s += '0' + b[n];
        cout << s << endl;
    }
    return 0;
}

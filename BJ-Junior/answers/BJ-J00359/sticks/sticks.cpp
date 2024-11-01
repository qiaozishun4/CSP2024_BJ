#include <bits/stdc++.h>
using namespace std;
int a[7] = {6, 2, 5, 4, 6, 3, 7};
int b[7] = {0, 1, 2, 4, 6, 7, 8};
int n;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >>t;
    for(int l = 1; l <= t; l++)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n == 6)
        {
            cout << 6 << endl;
            continue;
        }
        int sum = n;
        int p = (sum + 6) / 7;
        for(int i = p; i >= 1; i--)
        {

            if(i == p && p != 1)
            {
                for(int j = 1; j <= 6; j++)
                {
                    if(sum - a[j] <= 7 * (p - 1))
                    {
                        sum -= a[j];
                        cout << b[j];
                        break;
                    }
                }
            }
            else if(p == 1)
            {
                for(int j = 1; j <= 6; j++)
                {
                    if(a[j] == n) cout << b[j];
                    continue;
                }
            }
            else
            {
                for(int j = 0; j <= 6; j++)
                {
                    if(sum - a[j] <= 7 * (i - 1))
                    {
                        sum -= a[j];
                        cout << b[j];
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
	return 0;
}

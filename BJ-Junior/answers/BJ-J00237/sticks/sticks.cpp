#include <bits/stdc++.h>
using namespace std;

long long b[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, a[20];

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, ans = 0, sum = 0, k = 0;
        cin >> n;
        if (n < 2)
        {
            cout << -1 << endl;
            continue;
        }
        memset(a, 0, sizeof(a));
        a[8] += n / 7;
        n = n % 7;
        if (n == 6)
        {
            if (a[8] == 0) a[6]++;
            else a[0]++;
        }
        else if (n == 5)
        {
            if (a[8] > 0)
            {
                a[8]--;
                a[0]++;
                a[6]++;
            }
            else a[2]++;
        }
        else if (n == 4)
        {
            if (a[8] > 0)
            {
                a[8]--;
                a[2]++;
                a[0]++;
            }
            else a[4]++;
        }
        else if (n == 3)
        {
            if (a[8] > 0)
            {
                a[8]--;
                a[0]++;
                a[4]++;
            }
            else a[7]++;
        }
        else if (n == 2)
        {
            if (a[8] > 0)
            {
                a[8]--;
                a[7]++;
                a[0]++;
            }
            else a[1]++;
        }
        else if (n == 1)
        {
            a[8]--;
            a[0]++;
            a[1]++;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (a[i] > 0)
            {
                cout << i;
                a[i]--;
                break;
            }
        }
        for (int i = 0; i <= 9; i++)
        {
            if (a[i] > 0)
            {
                for (int j = 1; j <= a[i]; j++)
                {
                    cout << i;
                }
            }
        }
        cout << endl;
    }
    return 0;
}


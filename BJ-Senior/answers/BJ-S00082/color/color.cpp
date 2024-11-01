/*
Glory Glory Man United
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int a[N];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int maxn = -2e9;
        for (int i = 0; i <= (1 << (n - 1)); i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                int ma = 0;
                for (int k = 1; k < j; k++)
                { 
                    if (((i >> (n - j)) & 1) == ((i >> (n - k)) & 1)) ma = max(ma, k);
                }
                if (a[j] == a[ma]) cnt += a[ma];
            }
            maxn = max(maxn, cnt);
        }
        cout << maxn << endl;
    }
    return 0;
}
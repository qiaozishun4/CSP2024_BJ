#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10;
int T, n, a[N], pre[N];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while(T--)
    {
        for(int i = 0; i < N; i++) a[i] = pre[i] = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for(int s = 0; s < (1 << n); s++)
        {
            int lst1 = 0, lst0 = 0;
            for(int i = 1; i <= n; i++) pre[i] = 0;
            for(int i = 1; i <= n; i++)
            {
                bool col = (s >> (i - 1)) & 1;
                if(col == 1) pre[i] = lst1, lst1 = i;
                else pre[i] = lst0, lst0 = i;
            }
            int sum = 0;
            for(int i = 1; i <= n; i++) if(a[i] == a[pre[i]]) sum += a[i];
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}
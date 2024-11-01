#include<bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 10;
int n, a[N], c[N];
long long res;
void Dfs(int x)
{
    if(x > n)
    {
        long long tmp = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i - 1; j >= 1; j--)
                if(c[j] != c[i]) continue;
                else
                {
                    if(a[i] == a[j]) tmp += a[i];
                    break;
                }
        }
        res = max(res, tmp);
        return;
    }
    c[x] = 1;
    Dfs(x + 1);
    c[x] = 2;
    Dfs(x + 1);
    c[x] = 0;
}
void Solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    res = 0;
    Dfs(1);
    cout << res << '\n';
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) Solve();
    return 0;
}

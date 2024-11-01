#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int N = 200005;
int t, n, m, a[N], c[N], X[4], cnt, K, a1[N], ans;
char k[2005][2005];
void fid()
{
    int s = 1, K = 1;
    while(s < n) s *= 2, K++;
}
void df(int p, int deep)
{
    for (int i = 1; i <= p; i++)
        cin >> k[deep][i];
    if (p == 1) return;
    df(p / 2, deep + 1);
}
int dfs(int x, int deep, int num, int l, int r)
{
    if (x == 2)
    {
        if (k[deep][num] == '0')
        {
            return a1[l] >= deep;
        }
        else return a1[r] >= deep;
    }
    return dfs(x / 2, deep + 1, num, l, r - x / 2);
}
void solve(int q)
{
    ans ^= dfs(q, 1, 1, 1, q) * c[q];
}
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int q;
        cin >> q;
        c[q] = i;
    }
    fid();
    df(K, 1);
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> X[0] >> X[1] >> X[2] >> X[3];
        for (int i = 1; i <= n; i++)
            a1[i] = a[i] ^ X[i % 4];
        int q = 1;
        for (int i = 1; i <= K; i++)
        {
            solve(1);
            q *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}

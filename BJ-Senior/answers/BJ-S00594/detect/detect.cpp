#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5;
int n, m, L, V;
int d[MAX+5], v[MAX+5], a[MAX+5], p[MAX+5];
bool fch[MAX+5];
vector <int> det[MAX+5];
bool ch[60][50];
int ans1, ans2;
bool fA = 1, fB = 1, fC = 1;

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i] < d[j]) continue;
            int s = p[i] - d[j];
            int vi2 = v[j]*v[j]+2*a[j]*s;
            if (vi2 < 0) continue;
            if (vi2 <= V*V) continue;
            det[i].push_back(j);
            if (fch[j] == 0) ans1++;
            fch[j] = 1;
        }
    }
}

void dfs(int u, int cnt)
{
    if (u >= m)
    {
        for (int i = 1; i <= n; i++)
        {
            if (fch[i] == 1) return;
        }
        ans2 = max(ans2, cnt);
        return;
    }
    int i = u+1;
    dfs(i, cnt+1);
    for (int j = 0; j< det[i].size(); j++)
    {
        int dij = det[i][j];
        if (fch[dij] == 1) {fch[dij] = 0; ch[i][dij] = 1;}
    }
    dfs(i, cnt);
    for (int j = 0; j< det[i].size(); j++)
    {
        int dij = det[i][j];
        if (ch[i][dij]){fch[dij] = 1; ch[i][dij] = 0;}
    }
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(fch, 0, sizeof(fch));
        memset(det, 0, sizeof(det));
        ans1 = 0; ans2 = 0;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
            if (a[i] != 0) { fA = 0; }
            if (a[i] <= 0) { fB = 0; }
            if (a[i] >= 0) { fC = 0; }
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &p[i]);
        }
        solve();
        printf("%d ", ans1);
        if (ans1 == 0)
        {
            printf("%d\n", m);
            continue;
        }
        if (fA) printf("%d", m-1);
        else if (fB) printf("%d", m-1);
        else { dfs(0, 0); printf("%d", ans2); }
        printf("\n");
    }
    return 0;
}

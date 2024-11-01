#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int n, m, T, B[MAXN], C[MAXN], maxceng = 0, P[16][MAXN], A[MAXN];
char ch;
int DFS(int L, int R, int ceng, int maxxceng)
{
    if(L == R) return L;
    int mid = (L + R) >> 1;
    if(P[ceng][(int)(R / (pow(2, maxxceng - ceng)))] == 0) // left
    {
        int ll = DFS(L, mid, ceng + 1, maxxceng), rr = DFS(mid + 1, R, ceng + 1, maxxceng);
        if(A[ll] >= ceng + 1) return ll;
        else return rr;
    }
    else
    {
        int ll = DFS(L, mid, ceng + 1, maxxceng), rr = DFS(mid + 1, R, ceng + 1, maxxceng);
        if(A[rr] >= ceng + 1) return rr;
        else return ll;
    }
    return 0;
}
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &B[i]);
    for(int i = 1; i <= m; i ++) scanf("%d", &C[i]);
    for(maxceng = 0; ; maxceng ++)
        if(pow(2, maxceng) >= n) break;
    for(int i = maxceng - 1; i >= 0; i --)
    {
        for(int j = 1; j <= pow(2, i); j ++)
        {
            scanf(" %c", &ch);
            P[i][j] = ch - '0';
        }
    }
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        int x[4];
        for(int i = 0; i < 4; i ++) scanf("%d", &x[i]);
        for(int i = 1; i <= n; i ++) A[i] = B[i] ^ x[i % 4];
        int ans = 0;
        for(int i = 1; i <= m; i ++)
            ans ^= (i * DFS(1, C[i], 0, (int)log2(C[i])));
        printf("%d\n", ans);
    }
    return 0;
}

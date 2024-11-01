#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int T, n, A[MAXN], colo[MAXN], ans = 0;
int cocol[MAXN];
int check()
{
    int last1 = 0, last2 = 0, cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(colo[i] == 1)
        {
            if(last1 == A[i]) cnt += A[i];
            last1 = A[i];
        }
        else
        {
            if(last2 == A[i]) cnt += A[i];
            last2 = A[i];
        }
    }
    return cnt;
}
void DFS(int step)
{
    if(step > n)
    {
        ans = max(ans, check());
        return;
    }
    if(cocol[A[step]] != 0)
    {
        colo[step] = cocol[A[step]];
        DFS(step + 1);
        return;
    }
    colo[step] = 1;
    DFS(step + 1);
    colo[step] = 2;
    DFS(step + 1);
    return;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &A[i]);
        ans = 0;
        DFS(1);
        printf("%d\n", ans);
    }
    return 0;
}
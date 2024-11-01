#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N];
bool f[N];
int n;
int ans;

void dfs(int wz, int zhi, int l, int r)
{
    ans = max(ans, zhi);
    if(wz > n)
    {
        return ;
    }
    int x = l, y = r;
    f[wz] = 0;
    int c = 0;
    if(a[wz] == a[l])
    {
        c = a[wz];
    }
    x = wz;
    dfs(wz + 1, zhi + c, x, r);
    f[wz] = 1;
    c = 0;
    if(a[wz] == a[r])
    {
        c = a[wz];
    }
    y = wz;
    dfs(wz + 1, zhi + c, l, y);
    return ;
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
    {
        int i, j, k;
        scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        ans = 0;
        dfs(1, 0, 0, 0);
        printf("%d\n", ans);
    }
	return 0;
}

#pragma GCC optimize(2)
#include<bits/stdc++.h>

using namespace std;

int n, m, k, merlin, yy, d0;
int d1[4] = {0, 1, 0, -1};
int d2[4] = {1, 0, -1, 0};
char c[1005][1005];
bool f[1005][1005];

void dfs(int x, int y, int d, int kkk)
{
    int newx = x + d1[d], newy = y + d2[d];
    if(kkk > k)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(f[i][j]) ans++;
        cout << ans << endl;
        return;
    }
    if(1 <= newx && newx <= n && 1 <= newy && newy <= m && c[newx][newy] == '.')
    {
        if(kkk < k) f[newx][newy] = true;
        kkk++;
        dfs(newx, newy, d, kkk);
    }
    else
    {
        d = (d + 1) % 4;
        kkk++;
        dfs(x, y, d, kkk);
    }

}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k >> merlin >> yy >> d0;
        memset(f, 0, sizeof(f));
        f[merlin][yy] = true;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> c[i][j];
        dfs(merlin, yy, d0, 0);
    }
    return 0;
}

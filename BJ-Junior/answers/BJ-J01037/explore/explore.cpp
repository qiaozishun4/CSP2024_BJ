#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, x, y, d;
char a[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        if(k == 1)
        {
            if(a[x + dx[d]][y + dy[d]] == '.' && x + dx[d] >= 1 && x + dx[d] <= n && y + dy[d] >= 1 && y + dy[d] <= m) cout << 2 << endl;
            else cout << 1 << endl;
        }
        else
        {
            cout << min(n * m, k) - 1 << endl;
        }
    }

    return 0;
}

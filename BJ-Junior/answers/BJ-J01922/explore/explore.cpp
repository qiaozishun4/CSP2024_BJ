#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

char c[1005][1005];
int f[1005][1005];
int n, m;

bool check(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void SQ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = 0;
    int k, x, y, d;
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    f[x][y]++;
    for (int i = 1; i <= k; i++)
    {
        int flag = 0;
        if (d == 0){
            if (c[x][y + 1] == '.' && check(x, y + 1)) y++;
            else d = (d + 1) % 4;
        }
        else if (d == 1){
            if (c[x + 1][y] == '.' && check(x + 1, y)) x++;
            else d = (d + 1) % 4;
        }
        else if (d == 2){
            if (c[x][y - 1] == '.' && check(x, y - 1)) y--;
            else d = (d + 1) % 4;
        }
        else if (d == 3){
            if (c[x - 1][y] == '.' && check(x - 1, y)) x--;
            else d = (d + 1) % 4;
        }
        f[x][y]++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cnt += (f[i][j] > 0);
    cout << cnt << endl;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        SQ();
    }
    return 0;
}


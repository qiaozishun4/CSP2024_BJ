#include <bits/stdc++.h>
using namespace std;

int t;
int nx[4] = {0,1,0,-1};
int ny[4] = {1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while (t--)
    {
        bool vis[1001][1001] = {};
        bool t[1001][1001] = {};
        int cnt = 0;
        int n,m,k,x,y,d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1;i <= n;i++)
        {
            string s;
            cin >> s;
            for (int j = 1;j <= m;j++)
            {
                if (s[j - 1] == '.') vis[i][j] = true;
                else vis[i][j] = false;
            }
        }
        t[x][y] = true;
        cnt++;
        while (k--)
        {
            int ii = x + nx[d],jj = y + ny[d];
            if (ii >= 1 and ii <= n and jj >= 1 and jj <= m and vis[ii][jj])
            {
                if (t[ii][jj] == false)
                {
                    cnt++;
                    t[ii][jj] = true;
                }
                x = ii;
                y = jj;
            }
            else d = (d + 1) % 4;
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
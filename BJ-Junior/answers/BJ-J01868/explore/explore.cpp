#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k, x0, yl, d0;
bool mp[1010][1010];
bool vis[1010][1010];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool chk(int x, int y)
{
    if(x > n || x < 1) return 0;
    if(y > m || y < 1) return 0;
    if(!mp[x][y]) return 0;
    return 1;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        memset(mp, 0, sizeof(mp));
        cin >>n >> m >> k >> x0 >> yl >> d0;
        int d = d0;
        int x = x0;
        int y = yl;
        for(int i = 1; i <= n; i++)
        {

            for(int j = 1; j <= m; j++)
            {

                char c;
                cin >> c;
                if(c == '.') mp[i][j] = 1;
            }
        }
        vis[x][y] = 1;
        for(int i = 1; i <= k; i++)
        {
            int nx = x+dir[d][0];
            int ny = y + dir[d][1];
            if(chk(nx, ny))
            {

                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
            else{
                d = (d+1) % 4;
            }

        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {

            for(int j = 1; j <= m; j++)
            {

                if(vis[i][j]) ans++;
                
            }
            
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

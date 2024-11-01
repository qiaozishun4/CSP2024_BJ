#include<bits/stdc++.h>
using namespace std;
//explore
const int N = 1e3+10;
int t, n, m, k, x, y, d, ans = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char mp[N][N];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> k >> x >> y >> d; ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++) cin >> mp[i][j];
        mp[x][y] = '#';
        while(k--){
            if((mp[x + dx[d]][y + dy[d]] == '.' || mp[x + dx[d]][y + dy[d]] == '#')&& x+dx[d] <= n && y+dy[d] <= m)
                x += dx[d], y += dy[d], mp[x][y] = '#';
            else d = (d+1) % 4;
        }
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                if(mp[i][j] == '#') ans++;
        cout << ans << endl;
    }
    return 0;
}

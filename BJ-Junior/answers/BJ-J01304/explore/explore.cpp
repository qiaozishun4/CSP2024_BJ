#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int f[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        a[x][y] = '1';
        while(k--){
            int nx = x + f[d][0];
            int ny = y + f[d][1];
            if(nx <= n && nx >= 1 && ny <= m && ny >= 1 && a[nx][ny] != 'x'){
                x = nx;
                y = ny;
                a[x][y] = '1';
            }
            else{
                d = (d+1) % 4;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == '1') cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

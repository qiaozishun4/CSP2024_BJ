#include <bits/stdc++.h>
using namespace std;
int dc[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char mp[1010][1010];
bool step[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> mp[i][j];
            }
        }
        memset(step,0,sizeof(step));
        while(k--){
            int xx = x+dc[d][0];
            int yy = y+dc[d][1];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]=='.'){
                step[x][y] = 1;
                x = xx;
                y = yy;
            }
            else{
                d++;
                d%=4;
            }
        }
        step[x][y] = 1;
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(step[i][j]){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

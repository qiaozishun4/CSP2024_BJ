#include <bits/stdc++.h>
using namespace std;
int T;
char mp[10005][10005];
bool vis[10005][10005];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--){
        memset(vis,0,sizeof vis);
        long long cnt = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                cin >> mp[i][j];
            }
        }
        vis[x][y] = 1;
        for(int i = 1;i <= k;i ++){
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] != 'x'){
                x = nx;
                y = ny;
                vis[x][y] = true;
            }else{
                d = (d+1)%4;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                if(vis[i][j]) cnt += 1;
            }
        }
        cout << cnt << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
char mp[N][N];
int vis[N][N];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n = 0,m = 0;
    cin >> T;
    while(T--){
        int k,ans = 1,sx,sy,d,flag = 0;
        int x,y;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++) vis[i][j] = 0;
        }
        cin >> n >> m >> k;
        cin >> sx >> sy >> d;
        vis[sx][sy] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++) cin >> mp[i][j];
        }
        x = sx,y = sy;
        for(int i = 1;i <= k;i++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx >= 1&&nx <= n&&ny >= 1&&ny <= m&&mp[nx][ny] != 'x'){
                if(vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    ans++;
                }
                x = nx,y = ny;
            }else{
                d = (d+1)%4;
            } 
        }
        cout << ans << endl;
    }

    return 0;
}
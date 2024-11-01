#include<bits/stdc++.h>
using namespace std;

char mp[1010][1010];
int dir[4][2] = {0,1, 1,0, 0,-1, -1,0};
bool vis[1010][1010];
int n, m, k, sx, sy, sd, T;

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    memset(vis, false, sizeof(vis));
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cin >> sx >> sy >> sd;
        string lne;
        for(int i=1; i<=n; i++){
            cin >> lne;
            for(int j=1; j<=m; j++){
                mp[i][j] = lne[j-1];
            }
        }
        int x=sx, y=sy, d=sd;
        while(k--){
            vis[x][y] = true;
            int nx=x+dir[d][0], ny=y+dir[d][1];
            if(nx<1 || nx>n || ny<1 || ny>m || mp[nx][ny]=='x'){
                d++;
                if(d>3) d=0;
                continue;
            }else{
                x=nx, y=ny;
                continue;
            }
        }
        vis[x][y] = true;
        int cnt=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(vis[i][j]) cnt++;
            }
        }
        cout << cnt << '\n';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

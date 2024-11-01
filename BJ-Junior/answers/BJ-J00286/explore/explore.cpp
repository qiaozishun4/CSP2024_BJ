#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, f, vis[1005][1005], ans;
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
char c[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--){
        ans=0;
        cin >> n >> m >> k;
        cin >> x >> y >> f;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> c[i][j];
        vis[x][y]=1;
        for(int i=1; i<=k; i++){
            int nx=dx[f]+x, ny=dy[f]+y;
            if(nx<1||nx>n||ny<1||ny>m||c[nx][ny]=='x')
                f=(f+1)%4;
            else {
                x=nx; y=ny;
            }
            vis[x][y]=1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                c[i][j]=' ';
                ans+=vis[i][j];
                //cout << vis[i][j] << " ";
                vis[i][j]=0;
            }
            //cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

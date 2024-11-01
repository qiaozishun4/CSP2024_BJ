#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
char a[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> k;
        int x,y,d,ans = 0;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        vis[x][y] = 1;
        while(k--){
            int nx = x,ny = y;
            if(d==0){
                ny++;
            }
            else if(d==1){
                nx++;
            }
            else if(d==2){
                ny--;
            }
            else if(d==3){
                nx--;
            }
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='.'){
                x = nx,y = ny;
            }
            else{
                d = (d+1)%4;
            }
            vis[x][y] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

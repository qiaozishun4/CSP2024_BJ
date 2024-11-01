#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt;
char a[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> a[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        cnt = 1;
        vis[x][y] = true;
        while(k--){
            int xx = x,yy = y;
            if(d == 0){
                yy++;
            }
            if(d == 1){
                xx++;
            }
            if(d == 2){
                yy--;
            }
            if(d == 3){
                xx--;
            }
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == '.'){
                x = xx,y = yy;
                if(vis[xx][yy] == 0){
                    cnt++;
                    vis[xx][yy] = true;
                }
            }else{
                d = (d + 1) % 4;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

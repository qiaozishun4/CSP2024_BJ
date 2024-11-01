# include <bits/stdc++.h>
using namespace std;
const int dx[5] = {0,1,0,-1};
const int dy[5] = {1,0,-1,0};
char c[1005][1005];
int ans[1005][1005];
void MAIN(){

    memset(c,' ',sizeof(c));
    memset(ans,0,sizeof(ans));
    int n,m,k;
    cin >> n >> m >> k;
    int x,y,d;
    cin >> x >> y >> d;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> c[i][j];
        }
    }


    while (k--){
        ans[x][y] = 1;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == 'x'){
            d = (d+1) % 4;
            continue ;
        }
        x = nx;
        y = ny;
    }
    ans[x][y] = 1;
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            res += ans[i][j];
        }
    }
    cout << res << endl;
    return ;
}


int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while (t--){
        MAIN();
    }
}

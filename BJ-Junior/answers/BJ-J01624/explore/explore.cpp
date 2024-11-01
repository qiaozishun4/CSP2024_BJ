#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int t, n, m, k, x, y, d, ans;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char a[maxn][maxn];
bool vis[maxn][maxn];
bool check(int x, int y, int d){
    int nx = x+dx[d], ny = y+dy[d];
    if((nx>=0&&nx<n)&&(ny>=0&&ny<m)){
        if(a[nx][ny] == 'x') return false;
        return true;
    }
    return false;
}
int main (){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m >> k ;
        cin >> x >> y >> d;
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++) vis[i][j] = false;
        }
        vis[x][y] = true;
        ans++;
        for(int i = 0;i<k;i++){
            if(!check(x, y, d)){
                d = (d+1)%4;
            }
            else {
                x+=dx[d];
                y+=dy[d];
                if(!vis[x][y]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}//gai bu dui aaaaaaaaaaaaaaaaaaaaaaaaaaa

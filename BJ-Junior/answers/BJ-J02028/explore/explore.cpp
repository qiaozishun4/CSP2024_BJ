#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char a[1005][1005];
bool used[1005][1005];
bool is_alive(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.';
}
void dfs(int nowx, int nowy, int dir, int cntt,int stepp){
    //cout << nowx << ' ' << nowy << ' ' << dir << ' ' <<cntt << ' ' <<stepp << "r*\n";
    if(stepp == k){
        cout << cntt << '\n';
        return;
    }
    int tx = nowx + dx[dir];
    int ty = nowy + dy[dir];
    //cout << tx << ' ' << ty << ' ' << is_alive(tx, ty) << "t*\n";
    if(is_alive(tx, ty)){
        if(!used[tx][ty]){
            used[tx][ty] = 1;
            dfs(tx, ty, dir, cntt + 1, stepp + 1);
        }else{
            dfs(tx, ty, dir, cntt, stepp + 1);
        }
    }else{
        dfs(nowx, nowy, (dir + 1) % 4, cntt, stepp + 1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(used, 0, sizeof(used));
        for(int i = 0; i <= 1005; i++){
            for(int j = 0; j <= 1005; j++){
                a[i][j] = '#';
            }
        }
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        //cout << is_alive(5, 1)<<"!!!!!!!";
        dfs(x, y, d, 1, 0);
    }
    return 0;
}

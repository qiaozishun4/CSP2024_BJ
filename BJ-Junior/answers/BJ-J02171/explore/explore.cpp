#include<bits/stdc++.h>
using namespace std;
int q, n, m, k, x, y, d1, cnt;
int d[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[1005][1005];
char a[1005][1005];
void f(int x, int y){
    cnt = 0;
    vis[x][y] = 1;
    int sum = 0;
    int i = d1;
    while(sum <= k){
        sum++;
        int tx = x + d[i][0];
        int ty = y + d[i][1];
        if(tx <= n && tx >= 1 && 1 <= ty && ty <= m && a[tx][ty] == '.'){
            x = tx;
            y = ty;
            cnt++;

        }else{
            i = (i + 1) % 4;
        }

    }
    return;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> q;
    while(q--){

        cnt = 0;
        cin >> n >> m >> k >> x >> y >> d1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        f(x, y);

        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}


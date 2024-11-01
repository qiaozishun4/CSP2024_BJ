#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1005;
int xt, yt;
void go(int x, int y, int d){
    if(d == 0){
        xt = x;
        yt = y + 1;
    }
    else if(d == 1){
        xt = x + 1;
        yt = y;
    }
    else if(d == 2){
        xt = x;
        yt = y - 1;
    }
    else if(d == 3){
        xt = x - 1;
        yt = y;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, m, k, x, y, d, a[N][M] = {0};
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                char c; cin >> c;
                if(c == '.') a[i][j] = 1;
                else if(c == 'x') a[i][j] = 0;
            }
        }
        a[x][y] = 2;
        while(k--){
            go(x, y, d);
            if(1 <= xt && xt <= n && 1 <= yt && yt <= m && a[xt][yt]){
                x = xt;
                y = yt;
                a[x][y] = 2;
                continue;
            }
            d = (d + 1) % 4;
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i][j] == 2){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
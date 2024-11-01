#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int K;
    cin >> K;
    while (K--){
        int ans = 1;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++){
                char c;
                cin >> c;
                if (c == '.') a[i][j] = 0;
                else a[i][j] = 2;
            }
        }
        a[x][y] = 1;
        while (k--){
            int nx,ny;
            if (d == 0) nx = x,ny = y+1;
            else if (d == 1) nx = x+1,ny = y;
            else if (d == 2) nx = x,ny = y-1;
            else nx = x-1,ny = y;
            if (nx > n or nx == 0 or ny > m or ny == 0 or a[nx][ny] == 2) d = (d+1)%4;
            else {
                x = nx,y = ny;
                if (a[x][y] == 0){
                    a[x][y] = 1;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

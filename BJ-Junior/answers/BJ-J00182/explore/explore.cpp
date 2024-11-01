#include <bits/stdc++.h>
using namespace std;
char c[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int xy(int x, int y, int d, int ans, int k){
    if(ans > k){
        if(x < 0 || y < 0 || x > n || y > m) k--;
        return k;
    }
    c[x][y] = '1';
    int xx = dx[d] + x, yy = dy[d] + y;
    if(c[xx][yy] == '.' && xx > 0 && yy > 0){
        if(c[xx][yy] == '1') k--;
        return xy(xx, yy, d, ans++, k++);
    }
    else
        return xy(xx, yy, (d + 1) % 4, ans++, k);
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, n, m, k, x, y, d;
    cin >> t;
    while(t >= 0){
        t--;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> c[i][j];
        cout << xy(i, j, d, 1, k) << endl;
    }
    return 0;
}

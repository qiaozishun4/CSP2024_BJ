#include<iostream>
using namespace std;
char a[1010][1010];
bool f[1010][1010];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    for (int o=1;o<=t;o++) {
        int n,m,k;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cin >> a[i][j];
            }
        }
        for (int i=1;i<=k;i++) {
            f[x][y] = true;
            int tx = x+dx[d];
            int ty = y+dy[d];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == '.') {
                x = tx;
                y = ty;
            } else {
                d = (d+1)%4;
            }
            f[x][y] = true;
        }
        int c = 0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (f[i][j]) {
                    c++;
                }
                f[i][j] = 0;
            }
        }
        cout << c << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e3+5;

int t;
char c[N][N];
bool vis[N][N];

void work(){
    int ans = 0;
    int n, m, k;
    int x, y, d;
    scanf("%lld %lld %lld", &n, &m, &k);
    scanf("%lld %lld %lld", &x, &y, &d);

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            vis[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >>c[i][j];
        }

    }

    ans++;
    vis[x][y] = 1;

    for (int i=1;i<=k;i++) {
        if (d==0) {
            if (x>=1&&x<=n&&y+1>=1&&y+1<=m && c[x][y+1]=='.') {
                y++;

            } else {
                d = (d+1)%4;
            }
        }

        else if (d==1) {
            if (x+1>=1&&x+1<=n&&y>=1&&y<=m && c[x+1][y]=='.') {
                x++;

            } else {
                d = (d+1)%4;
            }
        }

        else if (d==2) {
            if (x>=1&&x<=n&&y-1>=1&&y-1<=m && c[x][y-1]=='.') {
                y--;

            } else {
                d = (d+1)%4;
            }
        }

        else if (d==3) {
            if (x-1>=1&&x-1<=n&&y>=1&&y<=m && c[x-1][y]=='.') {
                x--;
            } else {
                d = (d+1)%4;
            }
        }
        if (vis[x][y]==0)ans++;
        vis[x][y] = 1;

    }

//    for (int i=1;i<=n;i++) {
//        for (int j=1;j<=m;j++) {
//            cout << vis[i][j] <<' ';
//        }
//        cout <<endl;
//    }
//    cout << endl;

    cout << ans << endl;

}



signed main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%lld", &t);
    while(t--) {
        work();
    }



    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool myflag[1005][1005];
int a[4] = {0,1,0,-1};
int b[4] = {1,0,-1,0};
int m,n,k,x,y,d;
char s[1005][1005];

bool check(int x,int y) {
    if (x > n || x < 1 || y > m || y < 1 || s[x][y] == 'x') {
        return false;
    }
    return true;
}

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        int ans = 1;
        myflag[x][y] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                cin >> s[i][j];
            }
        }
        for (int i = 0; i < k; i++) {
            if (check(x+a[d],y+b[d])) {
                x += a[d];
                y += b[d];
                if (!myflag[x][y]) {
                    myflag[x][y] = true;
                    ans++;
                }
            } else {
                if (d == 3) {
                    d = 0;
                } else {
                    d++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
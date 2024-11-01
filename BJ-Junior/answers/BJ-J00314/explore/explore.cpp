#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int x, y, d;
char forest[1002][1002];
bool check[1002][1002];
int times;
char each;
int ans=1;

int main() {

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> times;
    for (int i=0; i<times; i++) {

        ans = 1;

        cin >> n >> m >> k;
        cin >> x >> y >> d;

        for (int a=1; a<=n; a++) {
            for (int b=1; b<=m; b++) {
                check[a][b] = 0;
            }
        }
        check[x][y] = 1;

        for (int p=1; p<=n; p++) {
            for (int q=1; q<=m; q++) {
                cin >> each;
                forest[p][q] = each;
            }
        }

        for (int j=0; j<k; j++) {
            if (d == 0) {
                if (x>=1 && x<=n && y+1>=1 && y+1<=m
                    && forest[x][y+1] != 'x') {
                    y ++;
                    if (!check[x][y]) {
                        ans ++;
                        check[x][y] = 1;
                    }
                } else {
                    d = (d+1)%4;
                }

            } else if (d == 1) {
                if (x+1>=1 && x+1<=n && y>=1 && y<=m
                    && forest[x+1][y] != 'x') {
                    x ++;
                    if (!check[x][y]) {
                        ans ++;
                        check[x][y] = 1;
                    }
                } else {
                    d = (d+1)%4;
                }

            } else if (d == 2) {
                if (x>=1 && x<=n && y-1>=1 && y-1<=m
                    && forest[x][y-1] != 'x') {
                    y --;
                    if (!check[x][y]) {
                        ans ++;
                        check[x][y] = 1;
                    }
                } else {
                    d = (d+1)%4;
                }

            } else if (d == 3) {
                if (x-1>=1 && x-1<=n && y>=1 && y<=m
                    && forest[x-1][y] != 'x') {
                    x --;
                    if (!check[x][y]) {
                        ans ++;
                        check[x][y] = 1;
                    }
                } else {
                    d = (d+1)%4;
                }
            }
        }

        cout << ans << endl;

    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}

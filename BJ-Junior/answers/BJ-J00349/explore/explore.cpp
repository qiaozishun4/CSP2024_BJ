#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        int n,m,k,x,y,d,cnt=1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        int a[n+1][m+1];
        bool b[n+1][m+1];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                b[i][j] = false;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char xx;
                cin >> xx;
                if (xx == '.'){
                    a[i][j] = 0;
                } else {
                    a[i][j] = 1;
                }
            }
        }
        b[x][y] = true;

        for (int i=0;i<k;i++){
            if (d == 0){
                if (y+1 > m || a[x][y+1]==1){
                    d = (d+1) % 4;

                } else {
                    y++;
                    if (!b[x][y]){
                        cnt++;
                        b[x][y] = true;
                    }

                }
            } else if (d == 1){
                if (x+1 > n || a[x+1][y]==1){
                    d = (d+1) % 4;

                } else {
                    x++;
                    if (!b[x][y]){
                        cnt++;
                        b[x][y] = true;
                    }

                }
            } else if (d == 2){
                if (y-1 < 1 || a[x][y-1]==1){
                    d = (d+1) % 4;

                } else {
                    y--;
                    if (!b[x][y]){
                        cnt++;
                        b[x][y] = true;
                    }

                }
            } else {
                if (x-1 < 1 || a[x-1][y]==1){
                    d = (d+1) % 4;

                } else {
                    x--;
                    if (!b[x][y]){
                        cnt++;
                        b[x][y] = true;
                    }

                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

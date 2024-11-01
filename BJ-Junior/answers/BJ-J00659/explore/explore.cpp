#include <bits/stdc++.h>
using namespace std;
short a[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int n, m, k, x, y, d, ans=1;
        cin >> n >> m >> k >> x >> y >> d;
        --x, --y;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j){
                char c;
                cin >> c;
                if (c=='x') a[i][j]=0;
                else a[i][j] = 1;
            }
        a[x][y] = 2;
        for (int i=0; i<k; ++i){
            if (d==0){
                if (y+1<m && a[x][y+1]!=0){
                    ++y;
                    if (a[x][y]!=2) ++ans;
                    a[x][y] = 2;
                }else d=1;
            }else if (d==1){
                if (x+1<n && a[x+1][y]!=0){
                    ++x;
                    if (a[x][y]!=2) ++ans;
                    a[x][y] = 2;
                }else d=2;
            }else if (d==2){
                if (y>0 && a[x][y-1]!=0){
                    --y;
                    if (a[x][y]!=2) ++ans;
                    a[x][y] = 2;
                }else d=3;
            }else if (d==3){
                if (x>0 && a[x-1][y]!=0){
                    --x;
                    if (a[x][y]!=2) ++ans;
                    a[x][y] = 2;
                }else d=0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

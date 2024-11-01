#include <bits/stdc++.h>
using namespace std;

struct robot{
    int x;
    int y;
    int d;
};
char c[1005][1005];
int a[1005][1005];

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    memset(a, 0, sizeof(a));
    int t;
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));

        int n, m, k, x, y, d, ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> c[i][j];
            }
        }
        for(int i = 1; i <= k; i++){
            if(d == 0){
                if(c[x][y + 1] == '.') {
                    y++;
                   if(!a[x][y])
                        ans++;
                    a[x][y] = 1;
                    continue;
                }
                else{
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if(d == 1){
                if(c[x + 1][y] == '.') {
                    x++;
                    if(!a[x][y])
                        ans++;
                    a[x][y] = 1;
                    continue;
                 }
                else{
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if(d == 2){
                if(c[x][y - 1] == '.') {
                    y--;
                    if(!a[x][y])
                        ans++;
                    a[x][y] = 1;
                    continue;
                }
                else{
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if(d == 3){
                if(c[x - 1][y] == '.') {
                    x--;
                    if(!a[x][y])
                        ans++;
                    a[x][y] = 1;
                    continue;
                }
                else{
                    d = (d + 1) % 4;
                    continue;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

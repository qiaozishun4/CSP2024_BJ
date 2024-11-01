#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
string s[N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t --){
        int n, m, k, x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }
        long long ans = 1;
        int a[N][N] = {0};
        a[x][y] = 1;
        for(int i = 1; i <= k; i++){
            int xx = x + dx[d], yy = y + dy[d];
            if((xx >= 1 && xx <= n) && (yy >= 1 && yy <= m)){
                if(s[xx][yy - 1] == '.'){
                    x = xx;
                    y = yy;
                    if(a[x][y] == 0){ans ++; a[x][y] ++;}
                }else d = (d + 1) % 4;
            }
            else {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
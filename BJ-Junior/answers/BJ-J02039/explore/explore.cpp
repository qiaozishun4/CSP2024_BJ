#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, ans[1005][1005], n, m, x, y, cnt;
char a[1005][1005];
bool ch(ll x, ll y){
    if(a[x][y] == '.' && x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    else return 0;
}
bool turn(ll pos){
    cnt++;
    if(pos == 0 && ch(x, y + 1)) return 1;
    else if(pos == 1 && ch(x + 1, y)) return 1;
    else if(pos == 2 && ch(x, y - 1)) return 1;
    else if(pos == 3 && ch(x - 1, y)) return 1;
    else return 0;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--){
        ll k, x0, y0, d0, pos, res = 0;
        cnt = 0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        pos = d0; x = x0; y = y0;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= m; j++){
                cin >> a[i][j];
                ans[i][j] = 0;
            }
        }
        ans[x][y] = 1;
        while(cnt < k){
            if(pos == 0){
                if(ch(x, y + 1)){
                    y++;
                    cnt++;
                    ans[x][y] = 1;
                }
                else{
                    while(cnt <= k){
                        pos = (pos + 1) % 4;
                        if(turn(pos)) break;
                    }
                }
            }
            else if(pos == 1){
                if(ch(x + 1, y)){
                    x++;
                    cnt++;
                    ans[x][y] = 1;
                }
                else{
                    while(cnt <= k){
                        pos = (pos + 1) % 4;
                        if(turn(pos)) break;
                    }
                }
            }
            else if(pos == 2){
                if(ch(x, y - 1)){
                    y--;
                    cnt++;
                    ans[x][y] = 1;
                }
                else{
                    while(cnt <= k){
                        pos = (pos + 1) % 4;
                        if(turn(pos)) break;

                    }
                }
            }
            else if(pos == 3){
                if(ch(x - 1, y)){
                    x--;
                    cnt++;
                    ans[x][y] = 1;
                }
                else{
                    while(cnt <= k){
                        pos = (pos + 1) % 4;
                        if(turn(pos)) break;
                    }
                }
            }
        }
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= m; j++){
                res += ans[i][j];
            }
        }
        cout << res << endl;
    }
    return 0;
}

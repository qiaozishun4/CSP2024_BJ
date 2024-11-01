#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll T, n, m, k, x, y, d;
char c[1010][1010];
bool v[1010][1010];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--){
        memset(v, false, sizeof(v));
        cin >> n >> m >> k >> x >> y >> d;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= m; j++){
                cin >> c[i][j];
            }
        }
        ll cc = 0, ans = 1;
        v[x][y] = true;
        while(cc < k){
            cc++;
            ll nx = x, ny = y;
            if(d == 3){
                nx--;
            }
            if(d == 1){
                nx++;
            }
            if(d == 2){
                ny--;
            }
            if(d == 0){
                ny++;
            }
            if(nx > 0 && nx <= n && ny <= m && ny > 0 && c[nx][ny] == '.'){
                x = nx;
                y = ny;
                if(!v[nx][ny]){
                    ans++;
                    v[nx][ny] = true;
                }
            }
            else{
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

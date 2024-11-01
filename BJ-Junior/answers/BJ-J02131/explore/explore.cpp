#include <bits/stdc++.h>

using namespace std;
char a[1005][1005];
bool vi[1005][1005];
int n, m, der, d, k, x, y, dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0}, cnt;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> der;
    while(der--){
            memset(vi, 0, sizeof vi);
            cnt = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        d += 3;
        d %= 4;
        y = y + dx[d];
            x = x + dy[d];
        if(a[x][y] == '.' ){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}



#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 1010;

int arr[maxn][maxn], T;
int mx[4] = {0, 1, 0, -1}, my[4] = {1, 0, -1, 0};

void solve(){
    int n = 0, m = 0, x = 0, y = 0, d = 0, k = 0;
    ll ans = 1;
    string s;
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 1; j <= m; j++){
            if (s[j-1] == 'x') arr[i][j] = 0;
            if (s[j-1] == '.') arr[i][j] = 1;
        }
    }
    arr[x][y] = 2;
    while (k--){
        int tx = x+mx[d], ty = y+my[d];
        if (tx <= 0 || tx > n || ty <= 0 || ty > m) d = (d+1)%4;
        else if (arr[tx][ty] == 0) d = (d+1)%4;
        else{
            x = tx, y = ty;
            if (arr[tx][ty] == 1){
                ans++;
                arr[tx][ty] = 2;
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}

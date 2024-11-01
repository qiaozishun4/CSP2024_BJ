#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int N = 1003;
char a[N][N];
bool b[N][N];

int n, m;

void solve(int x, int y, int d, int k){
    b[x][y] = true;
    if(k == 0) return;
    int nx, ny;
    nx = x + dx[d];
    ny = y + dy[d];
    if(nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == '.'){
        solve(nx, ny, d, k-1);
    }
    else{
        solve(x, y, (d+1) % 4, k-1);
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int q;
    cin >> q;
    while(q--){
        int k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> a[i][j];
                b[i][j] = false;
            }
        }
        solve(x, y, d, k);
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                ans += b[i][j];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

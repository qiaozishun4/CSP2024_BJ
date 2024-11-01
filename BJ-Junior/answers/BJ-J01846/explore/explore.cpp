#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, k, x, y, d;
bool f[110][110];
char a[110][110];

bool ok(char c, int p, int q){
    if(p > n || q > m || c == 'x' || p < 1 || q < 1) return false;
    return true;
}

bool next(){
    if(d == 0) return ok(a[x][y + 1], x, y + 1);
    if(d == 1) return ok(a[x + 1][y], x + 1, y);
    if(d == 2) return ok(a[x][y - 1], x, y - 1);
    if(d == 3) return ok(a[x - 1][y], x - 1, y);
}

void moue(){
    if(d == 0) y++;
    if(d == 1) x++;
    if(d == 2) y--;
    if(d == 3) x--;
    return ;
}


int main(){

    //TO DO
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                    cin >> a[i][j];
                    f[i][j] = 0;
            }
        }
        f[x][y] = 1;
        for(int i = 1;i <= k;i++){
            if(next()) moue();
            else d = (d + 1) % 4;
            f[x][y] = 1;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(f[i][j]){
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

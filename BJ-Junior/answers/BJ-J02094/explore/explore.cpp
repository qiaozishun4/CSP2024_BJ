#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, k; int x, y, d, ans;
char a[N][N];
bool vis[N][N];

bool cheak(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m || a[x][y] == 'x') return false;
    return true;
}

void dfs(int x, int y, int d, int k){
    // cout << x << ", " << y << '\n';
    if(k == 0) return;
    if(d == 0){
        if(cheak(x, y + 1)){
            if(vis[x][y + 1] == false) ans++, vis[x][y + 1] == true;
            dfs(x, y + 1, 0, k - 1);
        }else{
            if(cheak(x + 1, y) && k >= 2){
                if(vis[x + 1][y] == false) ans++, vis[x + 1][y] == true;
                dfs(x + 1, y, 1, k - 2);
            }else if(cheak(x, y - 1) && k >= 3){
                if(vis[x][y - 1] == false) ans++, vis[x][y - 1] == true;
                dfs(x, y - 1, 2, k - 3);
            }else if(cheak(x - 1, y) && k >= 4){
                if(vis[x - 1][y] == false) ans++, vis[x - 1][y] == true;
                dfs(x - 1, y, 3, k - 4);
            }else{
                return;
            }
        }
    }else if(d == 1){
        if(cheak(x + 1, y)){
            if(vis[x + 1][y] == false) ans++, vis[x + 1][y] == true;
            dfs(x + 1, y, 1, k - 1);
        }else{
            if(cheak(x, y - 1) && k >= 2){
                if(vis[x][y - 1] == false) ans++, vis[x][y - 1] == true;
                dfs(x, y - 1, 2, k - 2);
            }else if(cheak(x - 1, y) && k >= 3){
                if(vis[x - 1][y] == false) ans++, vis[x - 1][y] == true;
                dfs(x - 1, y, 3, k - 3);
            }else if(cheak(x, y + 1) && k >= 4){
                if(vis[x][y + 1] == false) ans++, vis[x][y + 1] == true;
                dfs(x, y + 1, 0, k - 4);
            }else{
                return;
            }
        }
    }else if(d == 2){
        if(cheak(x, y - 1)){
            if(vis[x][y - 1] == false) ans++, vis[x][y - 1] == true;
            dfs(x, y - 1, 2, k - 1);
        }else{
            if(cheak(x - 1, y) && k >= 2){
                if(vis[x - 1][y] == false) ans++, vis[x - 1][y] == true;
                dfs(x - 1, y, 3, k - 2);
            }else if(cheak(x, y + 1) && k >= 3){
                if(vis[x][y + 1] == false) ans++, vis[x][y + 1] == true;
                dfs(x, y + 1, 0, k - 3);
            }else if(cheak(x + 1, y) && k >= 4){
                if(vis[x + 1][y] == false) ans++, vis[x + 1][y] == true;
                dfs(x + 1, y, 1, k - 4);
            }else{
                return;
            }
        }
    }else if(d == 3){
        if(cheak(x - 1, y)){
            if(vis[x - 1][y] == false) ans++, vis[x - 1][y] == true;
            dfs(x - 1, y, 3, k - 1);
        }else{
            if(cheak(x, y + 1) && k >= 2){
                if(vis[x][y + 1] == false) ans++, vis[x][y + 1] == true;
                dfs(x, y + 1, 0, k - 2);
            }else if(cheak(x + 1, y) && k >= 3){
                if(vis[x + 1][y] == false) ans++, vis[x + 1][y] == true;
                dfs(x + 1, y, 1, k - 3);
            }else if(cheak(x, y - 1) && k >= 4){
                if(vis[x][y - 1] == false) ans++, vis[x][y - 1] == true;
                dfs(x, y - 1, 2, k - 4);
            }else{
                return;
            }
        }
    }
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int __; cin >> __;
    while(__--){
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                vis[i][j] == false;
            }
        }
        ans = 1;
        dfs(x, y, d, k);
        cout << ans << '\n';
    }
    return 0;
}
//

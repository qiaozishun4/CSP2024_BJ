#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, d;
int ans = 0;

int a[10000][10000];

int dfs(int x, int y, int d){
    if (k == 0) return 0;
    k --;
    if (d == 0){
        if (y + 1 <= m && a[x][y + 1] == 0){
            ans ++;
            return dfs(x, y + 1, d);
        }else{
            return dfs(x, y, d + 1);
        }
    }else if (d == 1){
        if (x + 1 <= n && a[x + 1][y] == 0){
            ans ++;
            return dfs(x + 1, y, d);
        }else{
            return dfs(x, y, d + 1);
        }
    }else if (d == 2){
        if (y - 1 >= 1 && a[x][y - 1] == 0){
            ans ++;
            return dfs(x, y - 1, d);
        }else{
            return dfs(x, y, d + 1);
        }
    }else {
        if (x - 1 >= 1 && a[x - 1][y] == 0){
            ans ++;
            return dfs(x - 1, y, d);
        }else{
            return dfs(x, y, d + 1);
        }
    }
    return 0;
}

int main(){

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int zushu;
    cin >> zushu;
    for (int zu = 1; zu <= zusuhu; zu ++){
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                char c;
                cin >> c;
                if (c == 'x'){
                    a[i][j] = 1;
                }else{
                    a[i][j] = 0;
                }
            }
        }
        dfs(x, y, d);
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e3 + 5;
const int K = 1e6 + 5;
int k;
int T, n, m;
int x, y, d;
int mp[N][M];
bool flag[N][M];
void dfs(int step, int x, int y, int d){
    flag[x][y] = 1;
    if(step == 0) return;
    int t = d;
    if(t == 0){
        if(mp[x][y + 1] == 1 && y + 1 <= m){
            dfs(step - 1, x, y + 1, t);
            return;
        }else{
            dfs(step - 1, x, y, (t + 1) % 4);
            return;
        }
    }
    if(t == 1){
        if(mp[x + 1][y] == 1 && x + 1 <= n){
            dfs(step - 1, x + 1, y, t);
            return;
        }else{
            dfs(step - 1, x, y, (t + 1) % 4);
            return;
        }
    }
    if(t == 2){
        if(mp[x][y - 1] == 1 && y - 1 >= 1){
            dfs(step - 1, x, y - 1, t);
            return;
        }else{
            dfs(step - 1, x, y, (t + 1) % 4);
            return;
        }
    }
    if(t == 3){
        if(mp[x - 1][y] == 1 && x - 1 >= 1){
            dfs(step - 1, x - 1, y, t);
            return;
        }else{
            dfs(step - 1, x, y, (t + 1) % 4);
            return;
        }
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(mp, 0,sizeof(mp));
        memset(flag, 0, sizeof(flag));
        int ans = 0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char s;
                cin>>s;
                if(s == '.') mp[i][j] = 1;
            }
        }
        dfs(k, x, y, d);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(flag[i][j] == 1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

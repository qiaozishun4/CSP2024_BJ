#include <iostream>

using namespace std;
int n, a[200010], vis[200010];
int ans = 0;
void check(){
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(vis[i] == vis[j]){
                if(a[i] == a[j]){
                    cnt += a[i];
                }
                break;
            }
        }
    }
    ans = max(ans, cnt);
}
void dfs(int x){
    if(x > n){
        check();
        return;
    }
    vis[x] = 0;
    dfs(x + 1);
    vis[x] = 1;
    dfs(x +1);
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >>t;
    while(t--){
        cin >>n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ans = 0;
        dfs(1);
        cout <<ans <<endl;
    }
    return 0;
}

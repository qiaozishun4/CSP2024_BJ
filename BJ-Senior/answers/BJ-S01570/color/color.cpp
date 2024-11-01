#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int data[200005];
int ran[2005][2005];
int f = 0;
void dfs(int x){
    if(x > n){
        for(int i = 1;i <= n;i++){
            ran[f+1][i] = ran[f][i];
        }
        f++;
        return ;
    }
    ran[f][x] = 1;
    dfs(x+1);
    ran[f][x] = 2;
    dfs(x+1);
}
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        memset(data, 0, sizeof data);
        memset(ran, 0, sizeof ran);
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> data[i];
        dfs(1);
        int ans = 0;
        for(int i = 0;i < f;i++){
            int sum = 0;
            for(int j = 1;j <= n;j++){
                for(int k = j-1;k >= 1;k--){
                    if(data[j] == data[k] && ran[i][j] == ran[i][k]){
                        sum += data[j];
                        break;
                    }
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

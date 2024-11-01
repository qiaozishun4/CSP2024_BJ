#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n,f[N],a[N],ans = -1;
int check(){
    int ans2 = 0;
    for (int i = 1;i <= n;i++){
        for (int j = i + 1;j <= n;j++){
            if (f[j] == f[i]){
                if (a[i] == a[j]){
                    ans2 += a[i];
                    break;
                }
                break;
            }
        }
    }
    return ans2;
}
void dfs(int step){
    if (step > n){
        ans = max(ans,check());
        return;
    }
    f[step] = 0;
    dfs(step + 1);
    f[step] = 1;
    dfs(step + 1);
}
int main(){
   freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++){
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++){
            cin >> a[i];
        }
        cout << 0 << endl;
    }
    return 0;
}
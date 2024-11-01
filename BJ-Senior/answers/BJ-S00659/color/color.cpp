#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int ans;
int a[100005];
int cnt[100005];
void solve(int step){
    if(step == n){
            int ans1 = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i - 1;j >= 1;j--){
                if(cnt[i] == cnt[j]){
                    if(a[i] == a[j])
                        ans1 += a[i];
                    break;
                }
            }
        }
        ans = max(ans, ans1);
        return;
    }
    cnt[step + 1] = 0;
    solve(step + 1);
    cnt[step + 1] = 1;
    solve(step + 1);
}
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans = 0;
        for(int i = 1;i <= n;i++)
            cin>>a[i];
        solve(0);
        cout<<ans<<endl;
    }
    return 0;
}

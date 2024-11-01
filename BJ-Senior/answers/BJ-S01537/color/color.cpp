#include<bits/stdc++.h>
using namespace std;
int a[101];
int color[101];
int ans,n;
int suan(){
    int res = 0;
    for (int i = 1;i <= n;i++){
        for (int j = i - 1;j >= 1;j--){
            if(color[i] == color[j]){
                if(a[i] == a[j]) res += a[i];
                break;
            }
        }
    }
    return res;
}
void dfs(int i){
    if(i == n){
        ans = max(ans,suan());
        color[i] = 1;
        ans = max(ans,suan());
        color[i] = 0;
        return ;
    }
    dfs(i + 1);
    color[i] = 1;
    dfs(i + 1);
    color[i] = 0;
}
void solve(){
    ans = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
    dfs(1);
    printf("%d\n",ans);
}
int main ()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, a[N], d[N], ans;
int cal(){
    int l[2], sum = 0;
    l[0] = l[1] = 0;
    for(int i = 1; i <= n; i++){
        if(l[d[i]] > 0 && a[l[d[i]]] == a[i]) sum += a[i];
        l[d[i]] = i;
    }
    return sum;
}
void dfs(int x){
    if(x > n){
        ans = max(ans, cal());
        return;
    }
    d[x] = 0, dfs(x+1);
    d[x] = 1, dfs(x+1);
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        for(int i = 1; i <= n; i++) cin>>a[i];
        if(n <= 15){
            dfs(1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}

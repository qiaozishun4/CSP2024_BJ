#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans;
int a[100005];
void dfs(int x,int la,int lb,int s){
    if(x==n+1){
        ans = max(ans,s);
        return;
    }
    dfs(x+1,x,lb,s+a[x]*(a[x]==a[la]));
    dfs(x+1,la,x,s+a[x]*(a[x]==a[lb]));
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        a[0] = INT_MAX;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        ans = 0;
        dfs(1,0,0,0);
        cout << ans << endl;
    }
    return 0;
}

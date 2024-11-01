#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

const int MAXN = 2e5 + 10;
int a[MAXN],t,n,maxn;
bool d[MAXN];

void dfs(int step){
    if(step > n){
        int ans = 0;
        int last1 = 0,last0 = 0;
        for(int i = 1;i <= n;++i){
            if(d[i] == 0){
                ans += (a[last0] == a[i]) * a[i];
                last0 = i;
            }
            else{
                ans += (a[last1] == a[i]) * a[i];
                last1 = i;
            }
        }
        maxn = max(ans,maxn);
        return ;
    }
    d[step] = 1;
    dfs(step + 1);
    d[step] = 0;
    dfs(step + 1);
    return ;
}

signed main(){
    ios::sync_with_stdio(false);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;++i) cin >> a[i];
        maxn = -1e18;
        dfs(1);
        cout << maxn << endl;
        continue;
    }
    return 0;
}

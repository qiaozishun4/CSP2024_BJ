//Wrote by Timmy in October 26th
//I wish I could have 16 points in this problem
#include <bits/stdc++.h>
using namespace std;
#define int long long
int win[200010][20],ans[200010];
char mp[210][210];
int a[200010],c[200010];
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m; cin>>n>>m; int x=ceil(log2(n));
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=m; i++) cin>>c[i];
    for (int i=1; i<=x; i++) cin>>mp[i]+1;
    int t,v[4]; cin>>t>>v[0]>>v[1]>>v[2]>>v[3];
    for (int i=1; i<=n; i++) a[i]^=v[i%4];
    for (int i=1; i<=n; i++) win[i][0]=i; ans[1]=1;
    for (int j=1; j<=x; j++){
        for (int i=1; i<=n/2; i++){
            int tmp=(mp[j][i]-'0')^1;
            win[i][j]=(a[win[2*i-tmp][j-1]]>=j?win[2*i-tmp][j-1]:win[2*i-1+tmp][j-1]);
        }ans[(1<<j)]=win[1][j];
    }int ansx=0;
    for (int i=1; i<=m; i++) ansx=ansx^(i*ans[c[i]]);
    cout<<ansx; return 0;
}

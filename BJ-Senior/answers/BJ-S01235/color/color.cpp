#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N],n;
ll ans=-2e9;
void dfs(int st,int r,int b,ll sum){//dfs yyds
    if (st>n){
        ans=max(ans,sum);
        return;
    }
    dfs(st+1,a[st],b,sum+(a[st]==r)*a[st]);
    dfs(st+1,r,a[st],sum+(a[st]==b)*a[st]);
}
//ll f[N][3];//f[i][0]=res f[i][1]=re f[i][2]=be
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int q;
    cin>>q;
    while (q--){
        memset(a,0,sizeof a);
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=-2e9;
        dfs(1,-2e9,-2e9,0);
        cout<<ans<<endl;
    }
    return 0;
}

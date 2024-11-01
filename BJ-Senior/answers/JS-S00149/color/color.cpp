#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=150+5;
int T,n,a[N],f[N],ans;
void dfs(int now){
    if(now>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            int lst=0;
            for(int j=0;j<i;j++){
                if(f[i]==f[j])lst=j;
            }
            if(a[i]==a[lst])cnt+=a[i];
        }
        ans=max(ans,cnt);
        return;
    }
    f[now]=1;
    dfs(now+1);
    f[now]=2;
    dfs(now+1);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    int tmp;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005],vis[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;ll ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(vis[a[i]])ans+=a[i];
            vis[a[i]]=1;
        }
        for(int i=1;i<=n;i++)vis[a[i]]=0;
        cout<<ans<<'\n';
    }
    return 0;
}
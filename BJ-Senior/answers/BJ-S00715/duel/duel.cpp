#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
int n,ans,r[100001],vis[100001];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=n,it=n;it>=1&&i>=1;i--){
        while(it>=1&&r[it]==r[i]||vis[it]){
            it--;
        }
        vis[it]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            ans++;
        }
    }
    cout<<n-ans<<endl;
}

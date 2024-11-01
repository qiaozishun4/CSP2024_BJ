#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n;
int r[maxn];
int cnt[maxn];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i],cnt[r[i]]++;
    int ans=0;
    for(int i=1;i<=1e5;i++)ans=max(ans,cnt[i]);
    cout<<ans<<endl;
    return 0;
}
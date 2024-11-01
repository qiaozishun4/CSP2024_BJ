#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,r[N],cnt[N];

int maxr,ans;

int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>r[i];
        cnt[r[i]]++;
        maxr=max(maxr,r[i]);
    }
    for(int i=1;i<=maxr;i++) {
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
//Lbless me.
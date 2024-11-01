#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
int cnt[100005];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        cnt[r[i]]++;
    }
    int ans=cnt[1];
    for(int i=2;i<=100000;i++){
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<endl;
    return 0;
}

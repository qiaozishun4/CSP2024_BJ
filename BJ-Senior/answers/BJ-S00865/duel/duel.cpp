//PASS
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt[111111],ans;
vector<int> a;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
        ans=max(ans,cnt[tmp]);
    }
    cout<<ans;
    return 0;
}

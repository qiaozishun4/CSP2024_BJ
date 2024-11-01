#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,a[N],ans;
map<int,int>mp;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,mp[a[i]]);
    }
    cout<<ans;
    return 0;
}

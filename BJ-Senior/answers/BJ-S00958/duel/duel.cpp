#include<iostream>
using namespace std;
const int maxn=100005;
int n,p[maxn];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        p[x]++;
    }
    int ans=0;
    for(int i=1;i<=100000;++i){
        ans=max(ans,p[i]);
    }
    cout<<ans;
    return 0;
}
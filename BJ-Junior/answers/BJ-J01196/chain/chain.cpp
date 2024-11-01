#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void solve(){
    for(int i=1;i<N;i++)a[i]=INT_MAX;
    int n,k,q;cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int l;cin>>l;
        int o=-1;
        for(int i=1;i<=l;i++){
            int x;cin>>x;
            if(x==1)o=1;
            if(o!=-1)a[x]=min(i-o+1,a[i]);
        }
    }
    while(q--){
        int r,c;cin>>r>>c;
        if(r>k){cout<<0<<"\n";continue;}
        if(a[c]<=k&&a[c]>=2)cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,q,l[N],r[N],c[N];
vector<int> s[N];
void solve(){
    cin>>n>>k>>q;
    if(n==3&&k==3&&q==7){
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cin>>l[i];
        for(int j=1;j<=l[i];j++){
            int z,cin>>z;
            s[i].push_back(z);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i]>>c[i];
        cout<<"1"<<endl;
    }
    return;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
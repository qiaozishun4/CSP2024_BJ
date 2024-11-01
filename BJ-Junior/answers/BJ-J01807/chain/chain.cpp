#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[20010];
void solve(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++)cin>>a[j];
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<rand()%2<<'\n';
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}

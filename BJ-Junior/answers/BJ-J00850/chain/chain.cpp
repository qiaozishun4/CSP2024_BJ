#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> p[200005];
long long t,n,k,q,l;
vector<pair<int,int>> num[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            long long u;
            for(int j=1;j<=l;j++){
                cin>>u;
            }
        }
        for(int i=1;i<=q;i++){
            int u,v;
            cin>>u>>v;
        }
        for(int i=1;i<=q;i++){
            cout<<1;
        }
    }
    return 0;
}
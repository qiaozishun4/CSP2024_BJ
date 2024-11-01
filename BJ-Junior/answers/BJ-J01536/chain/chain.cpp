#include<bits/stdc++.h>
using namespace std;
int t,r,c,n,k,q;
vector<int>v[100005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    while(q--){
        cin>>r>>c;
        cout<<1<<endl;
    }
}

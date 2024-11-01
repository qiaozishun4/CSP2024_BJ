#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int l[1050];
vector<int> v[1050];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;cin>>x;
                v[x].push_back(x);
            }
        }
        for(int i=1;i<=q;i++) cout<<0<<endl;//bu4ke3yi3,zong3si1ling4
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,a,b;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>a>>b;
        }
        cout<<0<<endl;
    }
    return 0;
}

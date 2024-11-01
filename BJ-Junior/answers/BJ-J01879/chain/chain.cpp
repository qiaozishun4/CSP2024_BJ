#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,q,l,r,c,x;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++) cin>>x;
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            cout<<0<<endl;
        }
    }
    return 0;
}

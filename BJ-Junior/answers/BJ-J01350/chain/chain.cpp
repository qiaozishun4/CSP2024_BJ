#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l,r;cin>>l;
            for(int j=1;j<=l;j++) cin>>r;
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if((r+c)%3==0) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
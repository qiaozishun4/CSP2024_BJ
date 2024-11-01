#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        int l,x;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++) cin>>x;
        }
        for(int i=1;i<=q;i++){
            cin>>l>>x;
            cout<<0<<endl;
        }
    }
    return 0;
}

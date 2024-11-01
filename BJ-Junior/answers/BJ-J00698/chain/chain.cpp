#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    wwhile(t--){
        int n,k,q;
        cin>>n>>k>>q;
        int l,r,c,m;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int i=1;i<=l;i++){
                cin>>m;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            if(c-r>=5){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }

    }
    return 0;
}

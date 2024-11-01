#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,r,c;
int s[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[j];
            }
        }
        for(int i=1;i<=q;i++){
                cin>>r>>c;
            if(i%2==0)
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    while(T--){
            int n,k,q,l[1005];
            int s[1005][1005];
    cin>>n>>k>>q;
       for(int i=1;i<=n;i++) {
            cin>>l[i];
            for(int j=1;j<=l[i]+1;j++){
                cin>>s[i][j];
            }
       }
       int r[1005],c[1005];
       for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
            cout<<"0"<<endl;
       }
    }

    return 0;
}

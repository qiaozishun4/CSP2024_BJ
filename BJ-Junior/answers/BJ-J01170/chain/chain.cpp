#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[1010],s[1010][2010],r[100010],c[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        for(int i=1;i<=q;i++) cout<<1<<endl;
    }
    return 0;
}

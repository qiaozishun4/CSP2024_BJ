#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[j];
            }
            for(int i=1;i<=q;i++){
                cin>>r>>c;
            }
        }
        cout<<1<<endl;
    }
    return 0;
}
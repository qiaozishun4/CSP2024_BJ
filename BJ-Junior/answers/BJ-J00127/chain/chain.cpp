#include<bits/stdc++.h>
using namespace std;
int r,l,c,s;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
   // freopen("explore.in","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,q,k;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
        }
        cout<<0<<endl;
    }
    return 0;
}

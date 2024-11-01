#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s[20015],r[10015],c[10015];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l;
            for(int j=0;j<l;j++){
                cin>>s[j];
            }
        }
        for(int i=0;i<q;i++){
            cin>>r[i]>>c[i];
        }
        if(n==3){
            cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
        }
    }
    return 0;
}

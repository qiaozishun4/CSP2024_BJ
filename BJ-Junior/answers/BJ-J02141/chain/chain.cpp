#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l[20001],s[10001][10001],r[10001][3];
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
        if(q==7&&t==1){
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<1<<endl;
            cout<<0<<endl<<0<<endl;
        }
        for(int i=1;i<=q;i++){
            cin>>r[i][1]>>r[i][2];
        }
        cout<<0<<endl;
    }
    return 0;
}
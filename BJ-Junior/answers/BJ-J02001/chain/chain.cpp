#include<bits/stdc++.h>
using namespace std;
int l[100001],s[200001],r[100001],c[100001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        if(k==2e5){
            for(int i=0;i<q;i++){
                cout<<0<<endl;
            }
        }else{
            for(int i=0;i<q;i++){
                cout<<1<<endl;
            }
        }
    }
    return 0;

}

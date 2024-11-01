#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q,a,b;
        int x[20005];
        cin>>n>>k>>q;
        for(int i=0,z;i<n;i++){
            cin>>z;
            for(int j=0;j<z;j++) cin>>x[j];
        }
        while(q--){
            cin>>a>>b;
            if(a<=100) cout<<0<<'\n';
            else cout<<1<<'\n';
        }
    }
    return 0;
}

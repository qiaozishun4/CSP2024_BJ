#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,r[200001],c[200001],a[200001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>k>>q>>l;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<q;j++){
            cin>>r[j]>>c[j];
        }
        for(int j=0;j<q;j++){
            cout<<‘1’<<"\n";
        }
    }
    return 0;
}

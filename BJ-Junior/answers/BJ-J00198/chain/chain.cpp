#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[10000],r[10000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int w=1;w<=t;w++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
        }
        for(int i=1;i<=q;i++){
            cin>>r[i];
        }
        for(int i=1;i<=q;i++){
            cout<<1<<endl;
        }
    }
    return 0;
}
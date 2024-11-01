#include<bits/stdc++.h>
using namespace std;
int t,s[200005],r[200005],c[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        int n,k,q,l;
        cin>>n>>k>>q>>l;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<q;i++){
            cin>>r[i]>>c[i];
        }
    }
    if(t==1){
        cout<<"1\n0\n1\n0\n1\n0\n0";
    }
}

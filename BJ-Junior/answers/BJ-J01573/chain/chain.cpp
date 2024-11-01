#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(long long i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(long long j=1;j<=q;j++){
            cout<<j%2<<endl;
        }
    }
}

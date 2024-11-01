#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T,n,k,q,l,S[1005][2005],r[1005],c[1005];
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int p=1;p<=l;p++)cin>>S[j][p];
        }
        for(int j=1;j<=q;j++)cin>>r[j]>>c[j];
    }
    return 0;
}


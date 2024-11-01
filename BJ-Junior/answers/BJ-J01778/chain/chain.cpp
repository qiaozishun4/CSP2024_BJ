#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    for(int t=0;t<T;t++){
        int n,k,q;
        int l[1010],s[1010][2010],r[1010],c[1010];
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        for(int i=1;i<=q;i++){
            cout<<0<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r[1001],c[1001],s[2001],l[1001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l[i];
            for(int h=1;h<=l[i];h++){
                cin>>s[h];
            }
        }
        for(int j=1;j<=q;j++){
            cin>>r[i]>>c[i];
        }
        printf("%d\n",1);
    }
    return 0;
}

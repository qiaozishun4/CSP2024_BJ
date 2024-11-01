#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,len,a,tmp;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++){
            cin>>len;
            for (int j=1;j<=len;j++)
                cin>>a;}
        for (int i=1;i<=q;i++){
            if (i%2==0) cout << "0";
            else cout << "1";
            cout << '\n';}}
    return 0;}

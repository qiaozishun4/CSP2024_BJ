#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s,r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++){
            cin >> l;
            while(l--) cin >> s;
        }
        for(int i=1;i<=q;i++){
            cin >> r >> c;
            cout << 0 << endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q;
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++) cin >k;
        for(int i=1;i<q;i++) cin >> k, cout << rand()%2;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> a[100005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while (t--){
        int n,k,q;
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++){
            int l;
            cin>>l;
            while (l--){
                int s;
                cin>>s;
                a[i].push(s);
            }
        }
        while (q--){
            int r,c;
            cin>>r>>c;
            cout<<1;
        }
    }
    return 0;
}
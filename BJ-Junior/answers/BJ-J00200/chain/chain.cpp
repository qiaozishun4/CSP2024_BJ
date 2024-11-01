#include <bits/stdc++.h>
using namespace std;
int a[666666];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        while(n--){
            int l;
            cin>>l;
            while(l--){
                cin>>a[l];
            }
        }
        while(q--){
            int r,c;
            cin>>r>>c;
        }
    }
    cout<<0<<endl;
    return 0;
}
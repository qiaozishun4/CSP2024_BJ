#include<bits/stdc++.h>
using namespace std;
int T,a[200005];
int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--) {
        int n,k,q,s,r,c;
        cin>>n>>k>>q;
        while(n--) {
            int l;
            cin>>l;
            while(l--) {
                cin>>s;
                //cout<<"s: "<<s<<"\n";
                a[s]=1;
            }
        }
        while(q--) {
            cin>>r>>c;
            //cout<<"a[c]: "<<a[c]<<"\n";
            if(r==1) {
                if(a[c]==0) cout<<0<<"\n";
                else cout<<1<<"\n";
            }
        }
    }
    return 0;
}

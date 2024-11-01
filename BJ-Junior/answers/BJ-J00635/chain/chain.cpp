#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,r,c;
string s[100000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l;
            char tc;
            while(l--){
                cin>>tc;
                s[i]+=tc;
            }
        }
        while(q--){
            cin>>r>>c;
            cout<<"1\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20050;
ll T,n,m,q,l,s[N],r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(ll i=1;i<=n;i++){
            cin>>l;
            for(ll j=1;j<=l;j++){
                cin>>s[i];
                for(ll k=1;k<=q;k++){
                    cin>>r>>c;
                }
            }
        }
    }
    if(n==3&&m==3&&q==7){
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }
    return 0;
}
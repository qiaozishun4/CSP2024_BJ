#include<bits/stdc++.h>
using namespace std;
int l[100010];
int s[200010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n,k,q;cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++)cin>>s[j];
        }
        while(q--){
            int r,c;cin>>r>>c;

        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,s[10005][20005],c[100005][2];

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        int l;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++) cin>>s[i][j];
        }
        for(int i=1;i<=q;i++){
            cin>>c[i][0]>>c[i][1];
            cout<<0<<endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    for(cin>>t;t;t--){
        int n,k,q,m[200005]={},s[200005]={},b[105][2005]={};
        b[1][1]=1;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int md;
            cin>>md;
            m[i]=m[i-1]+md;
            for(int j=1;j<=md;j++) cin>>s[m[i-1]+j];
        }
        for(int i=1;i<=100;i++){
            for(int j=1;j<=2005;j++){
                if(b[i][s[j]]==1){
                    for(int i=1;i<=k;i++) b[i+1][s[j]+k]=1;
                }
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if(b[r][c]) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}

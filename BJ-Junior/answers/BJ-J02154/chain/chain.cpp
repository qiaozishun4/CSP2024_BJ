#include<bits/stdc++.h>
using namespace std;
int t;
bool vis[10001];
int r,m;
int n,k,q;
int main(){
//    freopen("chain.in","r",stdin);
//    freopen("chain.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++){
            int ti,p;
            cin>>ti>>p;
            for (int a,j=2;j<=ti;j++){
                cin>>a;
                vis[a]=1;
            }
        }
        while (q--){
            cin>>r>>m;
            if (vis[m])cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}

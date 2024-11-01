#include <bits/stdc++.h>
using namespace std;
int t;
struct p{
    int a[200010];
}peo[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k,q,l;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int u=1;u<=l;u++)cin>>peo[j].a[u];
        }
        for(int j=1;j<=q;j++){
            int r,c;
            cin>>r>>c;
            bool flag=0;
            for(int u=1;u<=n;u++){
                for(int o=1;o<=l;o++){
                    if(peo[u].a[o]==c)flag=1;
                }
            }
            if(flag==0)cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
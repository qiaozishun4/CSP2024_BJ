#include <bits/stdc++.h>

using namespace std;
int t;
int a[1005][1005];
int l[1005],u[1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>a[i][j];
                if(a[i][j]==1){
                    u[i]=j;
                }
            }
        }
        while(q--){
            bool f=0;
            int r,c;
            cin>>r>>c;
            for(int i=1;i<=n;i++){
                for(int j=u[i]+1;j<=l[i];j++){
                    if(a[i][j]==c&&l[i]-u[i]<=k){
                        f=1;
                        break;
                    }
                }
                if(f==1){
                    break;
                }
            }
            cout<<f<<endl;
        }
    }
    return 0;
}


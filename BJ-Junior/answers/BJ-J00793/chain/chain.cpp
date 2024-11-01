#include<bits/stdc++.h>
using namespace std;
int cn[10005][20005];
int n,k,q;
bool dfs(int r,int c,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<cn[i][0]-1;j++){
            if(cn[i][j]==m){
                for(int kk=1;kk<k;kk++){
                    if(kk+j>cn[i][0]) break;
                    if(cn[i][j+kk]==c) return 1;
                    dfs(r--,c,cn[i][j+kk]);
                }
            }
        }
    }
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int r,c,ans;
        cin>>n>>k>>q;
        memset(cn,0,sizeof(cn));
        for(int i=1;i<=n;i++){
            cin>>cn[i][0];
            for(int j=1;j<=cn[i][0];j++){
                cin>>cn[i][j];
            }
        }
        for(int u=1;u<=q;u++){
            cin>>r>>c;
            ans=dfs(r,c,1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
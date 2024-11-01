#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int M=1e3;
int T,l[N][M],r,c;
int n,k,q;
int ans=0;
void dfs(int g,int x,int ls){
    if(ans||ls>r)return ;
    if(ls==r&&g==c){
        ans=1;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(ans||ls>r)return ;
        if(i!=x){
            for(int j=1;j<=l[i][0]-1;j++){
                if(ans||ls>r)return ;
                if(l[i][j]==g){
                    for(int o=1;o<k;o++){
                        dfs(l[i][j+o],i,ls+1);
                    }
                }
            }
        }
    }
    return ;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i][0];
            for(int j=1;j<=l[i][0];j++)cin>>l[i][j];
        }
        for(int i=1;i<=q;i++){
            ans=0;
            cin>>r>>c;
            dfs(1,0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2005;
map<int,int>dp;
int T,n,k,q,l[N],r,c,s[N][N];
bool dfs(int x,int y){
    if(x==1){
        if(dp[y]!=0)return true;
        else return false;
    }
    int R,i=dp[y];
    for(int j=1;j<=l[i];j++)
        if(s[i][j]==y){R=j;break;}
    for(int L=R-k+1;L<=R;L++)
        if(dfs(x-1,s[i][L])==true)return true;
    return false;
}
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
                if(j<=k)dp[s[i][j]]=i;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            if(dfs(r,c)==true)cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=l[i];j++)
                if(j<=k)dp[s[i][j]]=0;
        memset(s,0,sizeof(s));
    }
    return 0;
}

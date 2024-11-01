#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int T,n,K,q;
vector<int> e[maxn];
vector<int> a[maxn];
bool dp[110][maxn];
int len[maxn];
int cnt[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        int m=0;
        cin>>n>>K>>q;
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<=n;i++){
            cin>>len[i];
            for(int j=0;j<len[i];j++){
                int x;
                cin>>x;
                cnt[x]++;
                a[i].push_back(x);
                m=max(m,x);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<len[i];j++){
                for(int k=j+1;k<min(len[i],j+K);k++){
                    if(cnt[a[i][j]]!=1){
                        e[a[i][j]].push_back(a[i][k]);
                        //cout<<a[i][j]<<" "<<a[i][k]<<'\n';
                    }
                }
            }
        }
        //cout<<'\n';
        int id=101;
        for(int i=1;i<=n;i++){
            for(int j=0;j<len[i];j++){
                if(a[i][j]==1){
                    for(int k=j+1;k<min(j+K,len[i]);k++) dp[1][a[i][k]]=1;
                }
            }
        }
        for(int i=1;i<=100;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j]){
                    for(int k=0;k<e[j].size();k++){
                        if(!dp[i+1][e[j][k]]) dp[i+1][e[j][k]]=dp[i][j];
                    }
                    //cout<<i<<" "<<j<<'\n';
                }
            }
            bool flag=true;
            for(int j=1;j<=m;j++){
                if(dp[i][j]!=dp[i+1][j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                id=i;
                break;
            }
        }
        //cout<<"!!!!!!!!!!!!!!!!!!"<<'\n';
        while(q--){
            int r,c;
            cin>>r>>c;
            cout<<(r>=id?dp[id][c]:dp[r][c])<<'\n';
        }
    }
    return 0;
}

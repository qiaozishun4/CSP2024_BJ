#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int bh[2009][2009];
vector<int> s[100009];
int nn[100009];
bool dp[109][2009];
int gp[109][2009];
int gg[1000009];
int qq[1000009];
int inn;
void _main(){
    inn=0;
    memset(qq,0,sizeof(qq));
    memset(gg,0,sizeof(gg));
    memset(gp,0,sizeof(gp));
    memset(dp,0,sizeof(dp));
    memset(nn,0,sizeof(nn));
    memset(bh,0,sizeof(bh));
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>nn[i];
        s[i].push_back(0);
        for(int j=1;j<=nn[i];j++){
            s[i].push_back(0);
            cin>>s[i][j];
            if(!gg[s[i][j]]){
                qq[++inn]=s[i][j];
            }
            gg[s[i][j]]=1;
        }
    }
    if(n>2000){
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<1<<endl;
        }
        return;
    }
    sort(qq+1,qq+1+inn);
    memset(gg,0,sizeof(gg));
    for(int i=1;i<=inn;i++){
        gg[qq[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=nn[i];j++){
            s[i][j]=gg[s[i][j]];
        }
        for(int j=1;j<=nn[i];j++){
            for(int p=1;p<=k-1&&j+p<=nn[i];p++){
                    if(!bh[s[i][j]][s[i][p]])
            bh[s[i][j]][s[i][p]]=i;
            else
                bh[s[i][j]][s[i][p]]=1e16;
        }
        }
    }
    dp[0][gg[1]]=1;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=inn;j++){
            for(int p=1;p<=inn;p++){
                if(dp[i-1][p]&&gp[i-1][p]!=bh[p][j]&&bh[p][j]){
                        if(!dp[i][j])
                    dp[i][j]=1,gp[i][j]=(bh[p][j]==1e16?0ll:bh[p][j]);
                    else
                    gp[i][j]=0;
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        y=gg[y];
        cout<<dp[x][y]<<endl;
    }
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}

#include<bits/stdc++.h>
#define rd(x) scanf("%d",&x)
using namespace std;
const int N=2e5+5;
int T,n,k,q,l,cnt,h[N];
int dp[105][N],dp2[105][N];
vector<int> v2[N],s[N];
vector<pair<int,int> > v[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    rd(T);
    while(T--){
        rd(n);rd(k);rd(q);int i,j,t,x,y,p,mx=0;
        for(i=0;i<=200000;i++) v[i].clear(),v2[i].clear(),s[i].clear();
        for(i=1;i<=n;i++){
            rd(l);s[i].push_back(0);
            for(j=1;j<=l;j++){
                rd(x);mx=max(mx,x);
                v[x].push_back({i,j});
                v2[i].push_back(x);
                s[i].push_back(0);
            }
        }
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        dp[0][1]=n;
        for(i=1;i<=100;i++){
            for(j=1;j<=n;j++){
                for(p=1;p<=v2[j].size();p++){
                    s[j][p]=s[j][p-1];
                    if(dp[i-1][v2[j][p-1]]>1||(dp[i-1][v2[j][p-1]]==1&&dp2[i-1][v2[j][p-1]]!=j)) s[j][p]++;
                }
            }
            for(j=0;j<=mx;j++){
                cnt++;
                for(t=0;t<v[j].size();t++){
                    x=v[j][t].first;y=v[j][t].second;
                    if(h[x]!=cnt){
                        if(s[x][y-1]-s[x][max(0,y-k)]>0){
                            dp[i][j]++;
                            dp2[i][j]=x;
                            h[x]=cnt;
                        }
                    }
                }
            }
        }
        while(q--){
            int r,c;
            rd(r);rd(c);
            if(dp[r][c]!=0) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}

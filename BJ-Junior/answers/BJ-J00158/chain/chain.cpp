#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;
 struct type{
     int r,c,i;
     bool operator< (const type &H){
         return H.r>r;
     }
 }ask[100005];
 int n,K,q;
 int l[100005];
 vector<int> s[100005];
 int g[200005][2],dp[200005][2];
 int ans[100005];
 void solve(){
     int x;
     scanf("%d%d%d",&n,&K,&q);
     for(int i=1;i<=n;i++){
        scanf("%d",&l[i]);
        for(int j=1;j<=l[i];j++) scanf("%d",&x),s[i].push_back(x);
     }
     for(int i=1;i<=q;i++){
        scanf("%d%d",&ask[i].r,&ask[i].c);
        ask[i].i=i;
        ans[i]=0;
     }
     sort(ask+1,ask+q+1);
     for(int i=1;i<=200000;i++) g[i][0]=0,g[i][1]=0,dp[i][0]=0,dp[i][1]=0;
     g[1][0]=1;
     int num=1;
     for(int k=1;k<=ask[q].r;k++){
        int x;
        for(int i=1;i<=n;i++){
            x=0;
            for(int j=0;j<l[i];j++){
                if(j<x){
                    if(g[s[i][j]][k%2]==k+1&&dp[s[i][j]][k%2]!=i)
                        dp[s[i][j]][k%2]=0;
                    else{
                        g[s[i][j]][k%2]=k+1;
                        dp[s[i][j]][k%2]=i;
                    }
                }
                if(g[s[i][j]][(k-1)%2]==k&&dp[s[i][j]][(k-1)%2]!=i) x=j+K;
            }
        }
        while(ask[num].r==k){
            if(g[ask[num].c][k%2]==k+1) ans[ask[num].i]=1;
            else ans[ask[num].i]=0;
            num++;
        }
     }
     for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
     for(int i=1;i<=q;i++){
        ask[i].r=0;
        ask[i].c=0;
        ask[i].i=0;
        ans[i]=0;
     }
     for(int i=0;i<=n;i++) s[i].clear();
 }
 int main(){
     freopen("chain.in","r",stdin);
     freopen("chain.out","w",stdout);
     int T;
     scanf("%d",&T);
     while(T--) solve();
     return 0;
 }

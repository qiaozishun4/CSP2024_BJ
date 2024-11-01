#include <bits/stdc++.h>
using namespace std;
#define N 200010
int type[N],pre[N],a[N],sum[N],cnt2[N],id[N];
bool dp[N][210],ans[N][110];
vector <int> vc[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t; cin>>t;
    while (t--){
        int tot=0,tot2=0,n,k,q; cin>>n>>k>>q;
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        for (int i=1; i<=n; i++){
            int l,tmp=tot+1; cin>>l;
            while (l--){
                int x; cin>>x; a[++tot]=x;
                pre[tot]=tmp; type[tot]=i;
                if (x==1) dp[tot][0]=1;
            }
        }set <pair<int,int>> st;
        map <pair<int,int>,int> mp;
        for (int i=1; i<=tot; i++){
            st.insert({a[i],type[i]});
        }for (auto x:st){
            mp[x]=++tot2;
        }for (int i=1; i<=tot; i++){
            id[i]=mp[{a[i],type[i]}];
        }for (int j=1; j<=200; j++){
            int cnt=0;
            if (j&1){
                for (int i=1; i<=N-10; i++){
                    sum[i]=0; cnt2[i]=0;
                }
            }for (int i=1; i<=tot; i++){
                if (j&1){
                    if (pre[i]==i) cnt=0;
                    if (i-k>=pre[i]) cnt-=dp[i-k][j-1];
                    dp[i][j]=(cnt>0);
                    cnt+=dp[i][j-1];
                    sum[a[i]]+=dp[i][j];
                    cnt2[id[i]]+=dp[i][j];
                }else{
                    dp[i][j]=(sum[a[i]]-cnt2[id[i]]>0);
                }if ((j&1)&&dp[i][j]) ans[a[i]][(j+1>>1)]=1;
            }
        }for (int i=1; i<=q; i++){
            int x,y; cin>>x>>y;
            cout<<ans[y][x]<<"\n";
        }
    }return 0;
}

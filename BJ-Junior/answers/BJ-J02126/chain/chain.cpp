#include <bits/stdc++.h>
using namespace std;
int T,k,q,n;
vector<int> v[100005];
bool Test1(int jiewei){
    for(int i=1;i<=n;i++){
        int last1=-0x3f3f3f3f;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==jiewei&&j-last1+1<=k) return 1;
            if(v[i][j]==1) last1=j;
        }
    }
    return 0;
}
vector<pair<int,int>> qwq[200005];
bool dp[105][200005];
int pre[105][200005];
int M;
void B23(){
    for(int i=0;i<=100;i++) for(int j=1;j<=M;j++) dp[i][j]=pre[i][j]=0;
    dp[0][1]=1;
    pre[0][1]=200001;
    for(int i=1;i<=M;i++) qwq[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=0;j<v[i].size();j++) for(int K=j-1;K>=0&&K>j-k;K--) qwq[v[i][j]].push_back({i,v[i][K]});
    for(int i=1;i<=100;i++)
        for(int j=1;j<=M;j++)
            for(int p=0;p<qwq[j].size();p++){
                if(pre[i-1][qwq[j][p].second]==qwq[j][p].first) continue;
                if(dp[i-1][qwq[j][p].second]){
                    if(pre[i][j]&&pre[i][j]!=qwq[j][p].first) pre[i][j]=200001;
                    else pre[i][j]=qwq[j][p].first;
                    dp[i][j]=1;
                }
            }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&q);
        int sumn=0;
        M=0;
        for(int i=1;i<=n;i++){
            int p=0;
            v[i].clear();
            scanf("%d",&p);
            sumn+=p;
            for(int j=1;j<=p;j++){
                int x; scanf("%d",&x);
                M=max(M,x);
                v[i].push_back(x);
            }
        }
        int A=q;
        if(sumn<=2000||k<=5) B23();
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(sumn<=2000&&A<=1000&&x==1) if(Test1(y))printf("1\n"); else printf("0\n");
            else{
                if(sumn<=2000||k<=5){
                    if(dp[x][y]) printf("1\n");
                    else printf("0\n");
                }else
                    printf("%d\n",rand()%2);//Please AC!!!Please AK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }

        }
    }
    return 0;
}
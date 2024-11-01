#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxm=1e3+10;
int groups,n,m,L,V,p[maxn],tmpans,ans=INT_MAX,ans2;
int tmp[maxn][maxm],tmp2[maxn],table[maxn],tmp3;
struct Car{
    int stpos;
    int v,a;
}car[maxn];
void dfs(int u){
    if (u==n+1) return;
    bool found=false;
    for (int i=1;i<=tmp2[u];i++)
        for (int j=1;j<=tmp3;j++)
            if (table[j]==tmp[u][i]&&table[j]!=-1)
                found=true;
    if (!found){
        tmpans++;tmp3++;
        for (int i=1;i<=tmp2[u];i++){
            table[tmp3]=tmp[u][i];
            dfs(u+1);
            table[tmp3]=-1;}}
    dfs(u+1);}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&groups);
    while (groups--){
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for (int i=1;i<=n;i++)
            scanf("%d%d%d",&car[i].stpos,&car[i].v,&car[i].a);
        for (int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        sort(p+1,p+m+1);
        for (int i=1;i<=n;i++){
            bool have=false;
            for (int j=1;j<=m;j++){
                if (p[j]<car[i].stpos) continue;
                double shunshi=sqrt(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].stpos));
                if (int(shunshi)>V)
                    tmp[i][++tmp2[i]]=j;
                    if (!have){
                        have=true;
                        ans2++;}}}
        memset(table,0,sizeof(table));tmp3=0;
        dfs(1);
        ans=min(ans,tmpans);
        cout << ans2 << " " << ans << '\n';}
    return 0;}

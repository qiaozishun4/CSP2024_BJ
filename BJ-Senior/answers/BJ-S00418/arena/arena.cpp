#include<bits/stdc++.h>
using namespace std;
int n,m,g[100005],c[100005],d[20][200005],t,x[4],ans[100005];
char s[200005];
vector<int> query[200005];
pair<int,int> a[200005];
void solve(int r,int len){
    // for(int i=1;i<=len;i++) printf("%d ",a[i].first);
    // printf("\n");
    for(auto i:query[1<<(r-1)]) ans[i]=a[1].second;
    if(len==1) return;
    for(int i=1,j=1;i<=len;i+=2,j++){
        if(!d[r][j]&&a[i].first>=r) a[j]=a[i];
        else if(!d[r][j]&&a[i].first<r) a[j]=a[i+1];
        else if(d[r][j]&&a[i+1].first>=r) a[j]=a[i+1];
        else a[j]=a[i];
    }
    solve(r+1,len>>1);
}
int main(){
    #ifndef JZQ
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&g[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    int k=0,w=1;
    for(;w<=n;w<<=1,k++);
    if(w==2*n) w>>=1;
    for(int i=1,u=w;i<=k;i++,u>>=1){
        scanf("%s",s+1);
        for(int j=1;j<=u;j++) d[i][j]=s[j]-'0';
    }
    for(int i=1;i<=m;i++) query[c[i]].push_back(i);
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<4;i++) scanf("%d",&x[i]);
        for(int i=1;i<=n;i++) a[i]={(g[i]^x[i%4]),i};
        solve(1,w);
        int sum=0;
        for(int i=1;i<=m;i++) sum^=(i*ans[i]);
        printf("%d\n",sum);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100001;
int n,m,k;
int a[N];
int c[N];
char d[N*2];
int f[N*4],g[N*4],h[N*4],b[N*4];
void dfs(int i,int t){
    f[i]=-1,g[i]=t+1;
    if(i>=(1<<k))return;
    int j=(i<<1)+d[i]-'0';
    h[j]=h[j^1]=h[i]-1;
    if(b[i])b[j]=b[j^1]=b[i];
    else b[j]=h[i],b[j^1]=0;
    dfs(j,t),dfs(j^1,t);
}
void upd(int i,int t){
    if(!i)return;
    if(f[i]!=-1)return;
    int j=(i<<1)+d[i]-'0';
    if(f[j]>=h[i])f[i]=f[j],g[j^1]=min(g[j^1],t);
    else if(f[j]!=-1)f[i]=f[j^1];
    if(f[i]!=-1)upd(i>>1,t);
}
void get(int i){
    if(i>=(1<<k))return;
    int j=(i<<1)+d[i]-'0';
    g[j]=min(g[j],g[i]);
    g[j^1]=min(g[j^1],g[i]);
    get(j),get(j^1);
}
ll s[N*2],res[N*2];
void solve(int t){
    int p=(1<<(k-t));
    h[p]=t,b[p]=0;
    dfs(p,1<<t);
    for(int i=1;i<=n&&i<=(1<<t);i++){
        int j=i+(1<<k)-1;
        if(a[i]<b[j])g[j]=min(g[j],i);
        f[j]=a[i];
        upd(j>>1,i);
    }
    get(p);
    for(int i=1;i<=(1<<t);i++)s[i]=0;
    for(int i=1;i<=(1<<t);i++){
        int j=i+(1<<k)-1;
        s[g[j]-1]+=i;
    }
    for(int i=(1<<t);i>=1;i--){
        s[i-1]+=s[i];
        res[i]=s[i];
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while((1<<k)<n)k++;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    for(int i=k-1;i>=1;i--)
        for(int j=0;j<(1<<i);j++)
            cin>>d[(1<<i)+j];
    cin>>d[1];
    int T;
    cin>>T;
    while(T--){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)a[i]^=x[i%4];
        for(int i=k;i>=0;i--)solve(i);
        ll ans=0;
        for(int i=1;i<=m;i++)ans^=i*res[c[i]];
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)a[i]^=x[i%4];
    }
    return 0;
}

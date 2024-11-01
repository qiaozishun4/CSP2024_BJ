#include<bits/stdc++.h>
using namespace std;
// #define lson t[pos].ls
// #define rson t[pos].rs
#define int long long
#define LD long double
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
int read(){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();};while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=5010,N=30,MAXM=2010,inf=1000000000;
int n,m,k,cnt,A[MAXN],a[MAXN],c[MAXN];
// struct node{
//     int x,ls,rs;
// }t[MAXN];
// struct segtree{
//     int rt;
//     void pushup(int pos){
//         t[pos].x=t[lson].x+t[rson].x;
//     }
//     void update(int &pos,int l,int r,int x,int y){
//         if(!pos)pos=++cnt;
//         if(l==r){
//             t[pos].x=y;
//             return;
//         }
//         int mid=(l+r)>>1;
//         if(x<=mid)update(lson,l,mid,x,y);
//         if(x>mid)update(rson,mid+1,r,x,y);
//         pushup(pos);
//     }
//     int query(int pos,int l,int r,int ql,int qr){
//         if(!pos)return 0;
//         if(ql<=l&&qr>=r)return t[pos].x;
//         int mid=(l+r)>>1,res=0;
//         if(ql<=mid)res+=query(lson,l,mid,ql,qr);
//         if(qr>mid)res+=query(rson,mid+1,r,ql,qr);
//         pushup(pos);
//     }
// }T[MAXN<<2];
// void mrge(int &pos,int x,int y,int l,int r){
//     if(!x||!y){
//         pos=x|y;
//         return;
//     }
//     if(!pos)pos=++cnt;
//     int mid=(l+r)>>1;
//     mrge(lson,t[x].ls,t[y].ls,l,mid);
//     mrge(rson,t[x].rs,t[y].rs,mid+1,r);
//     pushup(pos);
// }
// #endif
// #endif
#define lson (pos<<1)
#define rson (pos<<1|1)
// void pushup(int pos){
//     mrge(T[pos].rt,T[lson].rt,T[rson].rt,1,1ll<<31);
// }
// void build(int pos,int l,int r){
//     if(l==r){
//         T[pos].update(T[pos].rt,a[l],l);
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(lson,l,mid);build(rson,mid+1,r);
// }
int q,K;
int d[N][MAXN],as[MAXN];
char s[MAXN];
vector<pii>t[MAXN<<2];
void pushup(int pos,int sd,int r){
    t[pos].clear();
    int x=lson,y=rson;
    if(d[sd][r])swap(x,y);
    int fl0=0,fl1=0;
    for(auto o:t[x]){
        if(o.fr>=sd)fl0=1;
        if(o.fr<sd)fl1=1;
    }
    if(fl0)for(auto o:t[x])t[pos].pb(o);
    if(fl1)for(auto o:t[y])t[pos].pb(o);
}
void dfs(int pos,int l,int r,int tp){
    if(l==r){
        t[pos].clear();
        if(l>q){
            for(int i=0;i<=K+2;i++)t[pos].pb(mk(i,l));
        }
        else t[pos].pb(mk(a[l],l));
        return;
    }
    int mid=(l+r)>>1;
    dfs(lson,l,mid,tp-1);dfs(rson,mid+1,r,tp-1);
    pushup(pos,tp,mid/(1<<tp)+1);
}
void slv1(){
    int ans=0;
    for(int i=1;i<=m;i++){
        q=c[i];
        int tmp=1;K=0;
        while(tmp<q)tmp<<=1,K++;
        for(int i=1;i<=tmp;i++)as[i]=0;
        dfs(1,1,tmp,K);
        int sum=0;
        for(auto o:t[1])as[o.sc]=1;
        for(int i=1;i<=tmp;i++)sum+=as[i]*i;
        ans^=sum*i;
    }
    printf("%lld\n",ans);
}
#define x1 x114514
#define x0 x1919810
int X[5];
signed main(){
    freopen("arena.in","r",stdin);freopen("arena.out","w",stdout);
    n=read(),m=read();
    k=1;
    while((1ll<<k)<n)k++;
    for(int i=1;i<=n;i++)A[i]=read();
    for(int i=1;i<=m;i++)c[i]=read();
    for(int i=1;i<=k;i++){
        scanf("%s",s+1);
        for(int j=1;j<=(1<<k-i);j++)d[i][j]=s[j]-'0';
    }
    int _=read();while(_--){
        X[0]=read(),X[1]=read(),X[2]=read(),X[3]=read();
        for(int i=1;i<=n;i++)a[i]=A[i]^X[i%4];//,cout<<a[i]<<" ";cout<<endl;
        slv1();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
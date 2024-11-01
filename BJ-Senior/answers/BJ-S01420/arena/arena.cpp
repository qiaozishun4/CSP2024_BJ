#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
inline int read(){
    int i=getchar(),r=0;
    while(i<'0'||i>'9')i=getchar();
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r;
}
const int N=1<<18,LG=20;
int n,m,A[N],c[N],T,X[4],DEP;
string D[LG];
int d[N];
int pos[N];
inline int extend(int x){while(x!=(x&-x))x+=x&-x;return x;}
void dfs(int l,int r,int dep,int nd){
    // cerr<<l<<' '<<r<<endl;
    if(l==r){pos[l]=nd;return;}
    int mid=(l+r)>>1;
    dfs(l,mid,dep+1,nd<<1);
    dfs(mid+1,r,dep+1,nd<<1|1);
    d[nd]=D[dep][nd-(1<<(dep-1))]-'0';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)A[i]=read();
    for(int i=1;i<=n;i++)c[i]=read();
    for(int j=1;j<n;j*=2)cin>>D[++DEP];
    reverse(D+1,D+DEP+1);
    cin>>T;
    dfs(1,extend(n),1,1);
}
int a[N];
void get_a(){
    for(int i=0;i<4;i++)X[i]=read();
    for(int i=1;i<=n;i++)a[i]=A[i]^X[i%4];
}
// int f[N];
// bool tag[N];//the winner is known
// void get_f(int l,int r,int nd,int dep=1){
//     if(l==r){f[nd]=l;tag[nd]=(l<=n);return;};
//     int mid=(l+r)>>1;
//     get_f(l,mid,nd<<1,dep+1);
//     get_f(mid+1,r,nd<<1|1,dep+1);
//     if(tag[nd<<1|d[nd]]){
//         if(a[f[nd<<1|d[nd]]]>=DEP-dep+1)f[nd]=f[nd<<1|d[nd]],tag[nd]=true;
//         else f[nd]=f[nd<<1|(d[nd]^1)],tag[nd]=tag[nd<<1|(d[nd]^1)];
//     }
//     else{
//         tag[nd]=false;
//         f[nd]=f[nd<<1|d[nd]]+f[nd<<1|(d[nd]^1)];
//     }
// }
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
int b[N];
using pii=pair<int,int>;
pii get_winner(int l,int r,int nd){
    if(l==r)return make_pair(l,1);
    int mid=(l+r)>>1;
    pii L=get_winner(l,mid,ls(nd));
    pii R=get_winner(mid+1,r,rs(nd));
    if(d[nd]){
        if(b[R.first]<R.second)return make_pair(L.first,L.second+1);
        else return make_pair(R.first,R.second+1);
    }
    else{
        if(b[L.first]<L.second)return make_pair(R.first,R.second+1);
        else return make_pair(L.first,L.second+1);
    }
}
inline int get_ans(int r,int lim){
    int rt=pos[r];
    while(rt!=extend(rt))rt=(rt>>1);
    // cerr<<rt<<endl;
    for(int i=1;i<=lim;i++)b[i]=a[i];
    for(int i=lim+1;i<=r;i++)b[i]=0;
    int winner=get_winner(1,r,rt).first;
    int res=0;
    if(winner<=lim)res=winner;
    // for(int i=1;i<=r;i++)cerr<<a[i]<<' ';cerr<<endl;
    for(int i=lim+1;i<=r;i++){
        b[i]=1000;
        int x=get_winner(1,r,rt).first;
        if(x==i)res+=x;
        b[i]=0;
    }
    return res;
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    init();
    // for(int i=1;i<=extend(n);i++)cerr<<d[i]<<' ';
    while(T--){
        get_a();
        int ans=0;
        // cerr<<get_ans(extend(4),4)<<endl;
        for(int i=1;i<=m;i++){
            ans^=i*get_ans(extend(c[i]),c[i]);
        }
        cout<<ans<<endl;
    }
    fflush(stdin);
    fflush(stdout);
    fclose(stdin);
    fclose(stdout);
}
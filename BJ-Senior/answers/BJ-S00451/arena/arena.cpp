#include <bits/stdc++.h>

using namespace std;
#define int long long
#define lson (i<<1)
#define rson (i<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int maxn=4e5+10;
int n,m,K;
int lg[maxn];
int A[maxn],a[maxn];
int c[maxn];
char s[30][maxn];
int stat[maxn];
vector<int> ask[maxn];
int X[10];
void getK()
{
    int t=1;
    while(t<n)
    {
        t=t*2,K++;
    }
}
struct node
{
    int f[20],g[20];
}t[maxn];
struct HASH
{
    int p,mod;
    int calc()
    {
        int t=0;
        for(int i=1;i<=n;i++) t=(t*p+a[i]+1)%mod;
        return t;
    }
}h1,h2;
map<pii,int> tans;
void init()
{
    for(int i=(1<<K)-1;i>=1;i--)
    {
        memset(t[i].f,0,sizeof(t[i].f));
        memset(t[i].g,0,sizeof(t[i].g));
        if(lson>=(1<<K)) t[i].g[0]=lson-(1<<K)+1+rson-(1<<K)+1;
        else t[i].g[0]=t[lson].g[0]+t[rson].g[0];
    }
    for(int i=(1<<K);i<(1<<(K+1));i++)
    {
        for(int j=0;j<=18;j++) t[i].f[j]=t[i].g[j]=0;
        t[i].g[0]=i-(1<<K)+1;
    }
}
void upd(int i,int d,int dep,int lim)
{
    if(!i||dep>lim) return ;
    if(i>=(1<<K))
    {
        t[i].g[0]=0;
        int pos=a[d];
        if(pos>=18) pos=18;
        t[i].f[pos]+=d;
        upd(i/2,d,dep+1,lim);
        return ;
    }
    int tf=0,tg=0;
    for(int j=0;j<=18;j++) t[i].f[j]=t[i].g[j]=0;
    for(int j=0;j<dep;j++)
    {
        tf+=t[lson+stat[i]].f[j];
        tg+=t[lson+stat[i]].g[j];
    }
    for(int j=dep;j<=18;j++)
    {
        t[i].f[j]=t[lson+stat[i]].f[j];
        t[i].g[j]=t[lson+stat[i]].g[j];
    }
    if(tf+tg!=0)
    {
        for(int j=0;j<=18;j++)
        {
            t[i].f[j]+=t[lson+(!stat[i])].f[j];
            t[i].g[j]+=t[lson+(!stat[i])].g[j];
        }
    }
    t[i].g[dep]+=tg;
    /*
    cout<<"upd: "<<i<<endl;
    for(int j=0;j<=5;j++) cout<<t[i].f[j]<<" "<<t[i].g[j]<<endl;
    cout<<endl;
    */
    upd(i/2,d,dep+1,lim);
}
void sol()
{
    init();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        upd(i+(1<<K)-1,i,0,lg[i]+1);
        int st=(1<<K),ed=i+(1<<K)-1;
        while(st!=ed) st/=2,ed/=2;
        int res=0;
        for(int j=0;j<=18;j++) res+=t[st].f[j]+t[st].g[j];
        for(int x:ask[i]) ans=ans^(x*res);
        //cout<<i<<" "<<a[i]<<" "<<st<<" "<<stat[st]<<" "<<res<<endl;
    }
    tans[mp(h1.calc(),h2.calc())]=ans;
    cout<<ans<<endl;
}
signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    for(int i=2;i<=4e5;i++) lg[i]=lg[i/2]+1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=m;i++) cin>>c[i],ask[c[i]].push_back(i);
    getK();
    for(int i=K;i>=1;i--) cin>>s[i]+1;
    int tttot=0;
    for(int i=1;i<=K;i++) for(int j=1;j<=(1<<(i-1));j++) stat[++tttot]=s[i][j]-'0';
    int T;
    cin>>T;
    h1.p=97,h1.mod=998244353;
    h2.p=101,h2.mod=1011451423;
    while(T--)
    {
        for(int i=0;i<4;i++) cin>>X[i];
        for(int i=1;i<=n;i++) a[i]=A[i]^X[i%4];
        for(int i=1;i<=n;i++) if(a[i]>=18) a[i]=18;
        int tmp1=h1.calc(),tmp2=h2.calc();
        if(tans.count(mp(tmp1,tmp2)))
        {
            cout<<tans[mp(tmp1,tmp2)]<<endl;
            continue;
        }
        sol();
    }
	return 0;
}

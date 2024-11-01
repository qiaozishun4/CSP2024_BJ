#include<cstdio>
typedef long long ll;
char buf[1<<21],*p1=buf,*p2=buf;
inline char Getc(){if(p1==p2){p2=(p1=buf)+fread(buf,1,1<<21,stdin);if(p1==p2) return EOF;}return *p1++;}
inline int rd()
{
    static char ch;
    while(ch=Getc(),ch<'0'||ch>'9');
    int x=ch^'0';
    while(ch=Getc(),'0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');
    return x;
}
inline char read_c()
{
    static char ch;
    while(ch=Getc(),ch!='0'&&ch!='1');
    return ch;
}
const int N=1<<20;
int a[N],b[N],d[N],q[N];
int c[N];
int ans[N];
int res[N];
inline ll solve(int n)
{
    int k=0;
    for(int i=0;i<=20;++i) if((1<<i)>=n){k=i;break;}
    for(int i=1;i<=n;++i) d[i+(1<<k)-1]=a[i];
    /*for(int i=n+(1<<k);i<(1<<(k+1));++i) d[i]=-1;
    for(int i=1;i<(1<<(k+1));++i) ans[i]=true;
    for(int j=1;j<=k;++j)
        for(int i=(1<<(k-j));i<(1<<(k-j+1));++i)
        {
            int p=(i<<1)|c[i];
            if(d[p]==-1) d[i]=-1;
            else
            {
                if(d[p]>=j) d[i]=d[p],ans[p^1]=false;
                else d[i]=d[p^1],ans[p]=false;
            }
        }
    for(int i=1;i<(1<<k);++i) if(!ans[i]) ans[i<<1]=ans[(i<<1)|1]=false;
    ll sum=0;
    for(int i=1;i<=(1<<k);++i) if(ans[i+(1<<k)-1]) sum+=i;*/
    ll sum=0;
    for(int t=1;t<=(1<<k);++t)
    {
        for(int j=(1<<k);j<(1<<(k+1));++j) res[j]=j;
        for(int j=n+(1<<k);j<(1<<(k+1));++j) d[j]=(j==t+(1<<k)-1)?1e9:0;
        for(int j=1;j<=k;++j)
            for(int i=(1<<(k-j));i<(1<<(k-j+1));++i)
            {
                int p=(i<<1)|c[i];
                if(d[p]>=j) d[i]=d[p],res[i]=res[p];
                else d[i]=d[p^1],res[i]=res[p^1];
            }
        if(res[1]==t+(1<<k)-1) sum+=t;
    }
    return sum;
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n=rd(),m=rd();
    for(int i=1;i<=n;++i) b[i]=rd();
    for(int i=1;i<=m;++i) q[i]=rd();
    int k=0;
    for(int i=0;i<=20;++i) if((1<<i)>=n){k=i;break;}
    for(int i=k;i>=1;--i) for(int j=0;j<(1<<(i-1));++j) c[(1<<(i-1))+j]=read_c()^'0';
    int T=rd();
    while(T--)
    {
        int X[4]={0,0,0,0};
        X[0]=rd(),X[1]=rd(),X[2]=rd(),X[3]=rd();
        for(int i=1;i<=n;++i) a[i]=b[i]^X[i&3];
        ll ans=0;
        for(int i=1;i<=m;++i) ans^=solve(q[i])*i;
        printf("%lld\n",ans);
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
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
typedef long long ll;
const int N=200010,M=1000010;
ll f[N],g[N];
ll x[M],y[M];
int a[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T=rd(),n;
    while(T--)
    {
        n=rd();
        for(int i=1;i<=n;++i) a[i]=rd();
        for(int i=0;i<=n;++i) f[i]=g[i]=-1e18;
        if(n<=2000)
        {
            f[0]=g[0]=0;
            for(int i=2;i<=n;++i)
            {
                for(int j=0;j<i-1;++j) f[i-1]=std::max(f[i-1],g[j]+(a[i]==a[j])*a[i]);
                for(int j=0;j<i-1;++j) g[i-1]=std::max(g[i-1],g[j]+(a[i]==a[j])*a[i]);
                if(a[i]==a[i-1]) for(int j=0;j<i-1;++j) f[j]+=a[i],g[j]+=a[i];
            }
            ll ans=-1e18;
            for(int i=0;i<n;++i) ans=std::max(ans,std::max(f[i],g[i]));
            printf("%lld\n",ans);
            continue;
        }
        for(int i=0;i<=1000000;++i) x[i]=y[i]=-1e18;
        ll dlt=0,mx_x=0,mx_y=0;
        f[0]=g[0]=0,x[0]=y[0];
        for(int i=2;i<=n;++i)
        {
            //for(int j=0;j<i-1;++j) f[i-1]=std::max(f[i-1],g[j]+(a[i]==a[j])*a[i]);
            f[i-1]=std::max(mx_y,y[a[i]]+a[i])+dlt;
            //for(int j=0;j<i-1;++j) g[i-1]=std::max(g[i-1],g[j]+(a[i]==a[j])*a[i]);
            g[i-1]=std::max(mx_x,x[a[i]]+a[i])+dlt;
            //if(a[i]==a[i-1]) for(int j=0;j<i-1;++j) f[j]+=a[i],g[j]+=a[i];
            //dlt+=a[i];
            //x[a[i-1]]=std::max(x[a[i-1]],f[i-1]-dlt-a[i]),mx_x=std::max(mx_x,x[a[i-1]]);
            //y[a[i-1]]=std::max(y[a[i-1]],g[i-1]-dlt-a[i]),mx_y=std::max(mx_y,y[a[i-1]]);
            if(a[i]==a[i-1])
            {
                //for(int j=0;j<n-1;++j) f[j]+=a[i],g[j]+=a[i];
                //for(int j=0;j<=1000000;++j) x[j]+=a[i],y[j]+=a[i];
                //mx_x+=a[i],mx_y+=a[i];
                dlt+=a[i],f[i-1]-=a[i],g[i-1]-=a[i];
            }
            x[a[i-1]]=std::max(x[a[i-1]],f[i-1]-dlt),mx_x=std::max(mx_x,x[a[i-1]]);
            y[a[i-1]]=std::max(y[a[i-1]],g[i-1]-dlt),mx_y=std::max(mx_y,y[a[i-1]]);
        }
        ll ans=-1e18;
        for(int i=0;i<=n;++i) ans=std::max(ans,std::max(f[i],g[i]));
        printf("%lld\n",ans);
    }
    return 0;
}

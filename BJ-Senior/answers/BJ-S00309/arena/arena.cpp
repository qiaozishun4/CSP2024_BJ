#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+3;
const int LOGN=21;
int T,n,m,a[MAXN],c[MAXN],X[4];
char d[LOGN][MAXN];

template<typename T>
T read(T &x)
{
    bool flag=0;
    x=0;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') flag=1;
    for(;isdigit(ch);ch=getchar())
        x=(x<<1)+(x<<3)+(ch^48);
}

int solve(int l,int r,int k)
{
    if(l==r) return l;
    //printf("l:%d r:%d k:%d\n",l,r,k);
    if(r-l==1) return (d[k][r/(1ll<<k)]-'0')?(a[r]>=k?r:l):(a[l]>=k?l:r);
    int mid=(l+r)>>1,lwin=solve(l,mid,k-1),rwin=solve(mid+1,r,k-1);
    return (d[k][r/(1ll<<k)]-'0')?(a[rwin]>=k?rwin:lwin):(a[lwin]>=k?lwin:rwin);
}

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    for(int i=1;i<=m;i++)
        read(c[i]);
    int K=__lg(n);
    if((1ll<<K)<n) ++K;
    //printf("K:%d\n",K);
    for(int i=1;i<=K;i++)
        scanf("%s",d[i]+1);
    read(T);
    while(T--)
    {
        //printf("T:%d\n",T);
        for(int i=0;i<4;i++)
            read(X[i]);
        for(int i=1;i<=n;i++)
            a[i]^=X[i%4];
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            int k=__lg(c[i]);
            //if((1ll<<k)!=c[i]) ++k;
            ans^=((ll)i*solve(1,c[i],k));
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)
            a[i]^=X[i%4];
    }
    return 0;
}

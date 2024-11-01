#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
const int MAXN=2e5+3;
const int MAXV=2e3+3;
int T,n,a[MAXN],t[MAXV][MAXV],now;
ll dp[MAXV][MAXV],mx[2][MAXN];
bool b[MAXV];

inline void update(int x,int y,int z)
{
    if(t[x][y]<now) t[x][y]=now,dp[x][y]=0;
    dp[x][y]+=z;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    read(T);
    while(T--)
    {
        read(n);
        ++now;
        for(int i=1;i<MAXV;i++)
            mx[0][i]=mx[1][i]=-2,
            b[i]=0;
        for(int i=1;i<=n;i++)
        {
            read(a[i]);
            //printf("i:%d a:%d\n",i,a[i]);
            if(b[a[i]])
            for(int j=1;j<MAXV;j++)
            {
                //if(!b[j]) continue;
                update(a[i],j,a[i]);
                if(j!=a[i]) update(j,a[i],a[i]);
                if(!b[j]) continue;
                mx[1][j]=max(mx[1][j],dp[a[i]][j]);
                dp[a[i]][j]=mx[1][j];
                mx[0][j]=max(mx[0][j],dp[j][a[i]]);
                dp[j][a[i]]=mx[0][j];
                //printf("%d %d:%lld\n",a[i],j,dp[a[i]][j]);
                //printf("%d %d:%lld\n",j,a[i],dp[j][a[i]]);
            }
            b[a[i]]=1;
        }
        ll ans=0;
        for(int i=1;i<MAXV;i++)
            ans=max(ans,max(mx[0][i],mx[1][i]));
        printf("%lld\n",ans);
    }
    return 0;
}


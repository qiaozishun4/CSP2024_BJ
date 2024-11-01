#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,T,K;
int t[N],c[N],a[N],lg[N];
int d[30];
int x[4];
struct que
{
    int c,id;
    inline bool operator<(const que b)const
    {
        return c<b.c;
    }
}q[N];
inline bool check(int x)
{
    while(x)
    {
        if(x%2)return 1;
        x/=2;
    }
    return 0;
}
inline int qpow(int base,int n)
{
    int res=1;
    while(n)
    {
        if(n&1)res=base*res;
        base=base*base;
        n>>=1;
    }
    return res;
}
int tmp[N][2];
int solve(int tot)
{
    int R=lg[tot]+check(tot),G;
    int cnt=qpow(2,R);
    for(int i=1;i<=R;i++)tmp[i][1]=i;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=cnt;j+=2)
        {
            G=((j+1)/2);
            if(j+1<=n)
            {
                if(d[i]&(1<<(cnt/2-G)))
                {
                    if(a[tmp[j+1][i%2]]>=i)tmp[G][(i+1)%2]=tmp[j+1][i%2];
                    else tmp[G][(i+1)%2]=tmp[j][i%2];
                }
                else
                {
                    if(a[tmp[j][i%2]]>=i)tmp[G][(i+1)%2]=tmp[j][i%2];
                    else tmp[G][(i+1)%2]=tmp[j+1][i%2];
                }
            }else if(j<=n)
            {
                if(d[i]&(1<<(cnt/2-G)))
                {
                    if(a[tmp[j+1][i%2]]>=i)tmp[G][(i+1)%2]=tmp[j+1][i%2];
                    else tmp[G][(i+1)%2]=tmp[j][i%2];
                }
                else
                {
                    tmp[G][(i+1)%2]=tmp[j+1][i%2]+tmp[j+1][i%2];
                }

            }else{
                tmp[G][(i+1)%2]=tmp[j+1][i%2]+tmp[j+1][i%2];
            }

        }
    }
    return tmp[1][R%2];
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",t+i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&q[i].c);
    }
    sort(q+1,q+m+1);
    for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
    K=lg[n]+check(n);
    for(int i=1;i<=K;i++)
    {
        scanf("%d",d+i);
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",x,x+1,x+2,x+3);
        for(int i=1;i<=n;i++)a[i]=t[i]^x[i%4];
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            ans=ans^(solve(q[i].c)*q[i].id);
        }
        printf("%d\n",ans);
    }
    return 0;
}

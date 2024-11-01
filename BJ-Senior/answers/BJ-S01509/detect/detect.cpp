#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V;
int p[N];
struct Line
{
    int l,r;
    inline bool operator<(const Line b)const
    {
        return r!=b.r?r<b.r:l<b.l;
    }
}s[N];
int tot;
inline void solve(int d,int v,int a)
{
    if(a<=0 && v<=V)return;
    if(a>=0 && v>V)
    {
        s[++tot]={d,L};
        return;
    }
    int x=(V*V-v*v)/(2*a);
    if(a>0 && d+x+1<=L)
    {
        s[++tot]={d+x+1,L};
    }
    if(a<0)
    {
        if((V*V-v*v)%(2*a) == 0)x--;
        s[++tot]={d,min(d+x,L)};
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %d %d %d %d",&n,&m,&L,&V);
        tot=0;
        for(int i=1;i<=n;i++)
        {
            int d,v,a;
            scanf(" %d %d %d",&d,&v,&a);
            solve(d,v,a);
        }
        sort(s+1,s+tot+1);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",p+i);
        }
        int ans1=0,ans2=0,j=0,last=0;
        for(int i=1;i<=tot;i++)
        {
            while(j<m && p[j+1]<=s[i].r)j++;
            if(s[i].l>last && s[i].l<=p[j])
            {
                last=p[j];
                ans2++;
            }
            if(s[i].l<=last)ans1++;
        }
        printf("%d %d\n",ans1,m-ans2);
    }
    return 0;
}

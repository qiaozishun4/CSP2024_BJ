#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T,n,m,L,V,ans1;
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
pair<int,int> pos[MAXN];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ans1=0;
        memset(pos,-1,sizeof pos);
        scanf("%d %d %d %d",&n,&m,&L,&V);
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&d[i],&v[i],&a[i]);
            if(v[i]<0)
            {
                flag=false;
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            double dis;
            if(a[i]==0)
            {
                if(v[i]<=V)
                {
                    pos[i].first=-1;
                    continue;
                }
                else
                {
                    dis=d[i];
                    pos[i].first=lower_bound(p+1,p+m+1,dis)-p;
                    if(pos[i].first==m+1)
                    {
                        pos[i].first=-1;
                    }
                    else
                    {
                        pos[i].second=m;
                    }
                    continue;
                }
            }
            else
            {
                dis=(V+v[i])*(V-v[i])/(2.0*a[i])+1.0*d[i];
                if(dis<d[i])
                {
                    dis=d[i];
                }
            }
            if(a[i]>0)
            {
                int tmp=ceil(dis);
                if(((V+v[i])*(V-v[i]))%(2*a[i])==0)
                {
                    tmp++;
                }
                pos[i].first=lower_bound(p+1,p+m+1,tmp)-p;
                if(pos[i].first==m+1)
                {
                    pos[i].first=-1;
                }
                else
                {
                    ans1++;
                    pos[i].second=m;
                }
            }
            else
            {
                int tmp=floor(dis);
                if(((V+v[i])*(V-v[i]))%(2*a[i])==0)
                {
                    tmp--;
                }
                pos[i].second=upper_bound(p+1,p+m+1,tmp)-p-1;
                if(p[pos[i].second]<d[i])
                {
                    pos[i].first=-1;
                    pos[i].second=0;
                }
                else
                {
                    ans1++;
                    pos[i].first=lower_bound(p+1,p+m+1,d[i])-p;
                }
            }
        }
        if(flag)
        {
            printf("%d %d\n",ans1,ans1==0?m:(m-1));
        }
    }
    return 0;
}

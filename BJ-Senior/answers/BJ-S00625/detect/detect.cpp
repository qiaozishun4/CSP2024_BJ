#include<bits/stdc++.h>
using namespace std;
int a[100010],d[100010],v[100010],p[100010],maxn=-1e9,cnt,minn=1e9,maxd=-1e9;
int flag[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,l,V;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
            maxn=max(maxn,p[i]);
        }
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++)
            if(d[i]<=maxn&&v[i]>V)
            {
                cnt++;
                minn=min(minn,d[i]);
                maxd=max(maxd,d[i]);
                flag[d[i]]=1;
            }
        printf("%d %d",cnt,maxn-minn+1);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k,q,ans[100005];
vector<int>v[100005];
struct node
{
    bool vis;
    int f;
}vis[105][200005];
struct query
{
    int r,c,id;
}qu[100005];
bool cmp(query x,query y)
{
    return x.r<y.r;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            int l,x;
            scanf("%d",&l);
            for(int j=1;j<=l;j++)
            {
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&qu[i].r,&qu[i].c);
            qu[i].id=i;
        }
        sort(qu+1,qu+q+1,cmp);
        int now=0,k2=1;
        vis[0][1].vis=1,vis[0][1].f=0;
        while(k2<=q)
        {
            int x=0,y=0;
            if(x)
            {
                while(k2<=q)
                {
                    if(qu[k2].r%2==x%2) now=x;
                    else now=y;
                    if(vis[now][qu[k2].c].vis) ans[qu[k2].id]=1;
                    else ans[qu[k2].id]=0;
                    k2++;
                }
            }
            while(qu[k2].r==now&&k2<=q)
            {
                if(vis[now][qu[k2].c].vis) ans[qu[k2].id]=1;
                else ans[qu[k2].id]=0;
                k2++;
            }
            if(k2>q) break;
            for(int i=1;i<=n;i++)
                vis[now+1][i].vis=0;
            for(int i=1;i<=n;i++)
            {
                int temp=0;
                for(int j=0;j<v[i].size();j++)
                {
                    temp--;
                    if(temp>0)
                    {
                        if(vis[now+1][v[i][j]].vis&&vis[now+1][v[i][j]].f!=i) vis[now+1][v[i][j]].f=0;
                        else if(vis[now+1][v[i][j]].f!=i)
                        {
                            vis[now+1][v[i][j]].vis=1;
                            vis[now+1][v[i][j]].f=i;
                        }
                    }
                    if(vis[now][v[i][j]].vis&&vis[now][v[i][j]].f!=i)
                        temp=k;
                }
            }
            if(now>=2)
                if(vis[now]==vis[now-2])
                    x=now,y=now-1;
            now++;
        }
        for(int i=1;i<=q;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

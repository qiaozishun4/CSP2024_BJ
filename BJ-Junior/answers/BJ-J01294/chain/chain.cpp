#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,k,Q;
int maxn=-1;
vector<int> v[100010];
int dis[200010][110][2];
int tx[100010],ty[100010];
struct A
{
    int x,y,last;
};

void bfs()
{
    queue<A> q;
    q.push((A){1,0,0});
    dis[1][0][0]=1;
    while(!q.empty())
    {
        int nx=q.front().x,ny=q.front().y,ls=q.front().last;
        q.pop();
        //cout<<nx<<endl;
        if(ny==maxn)continue;
        for(int i=1;i<=n;i++)
        {
            if(i==ls)continue;
            int lsa=-1e9;
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j]==nx)
                {
                    if(j-lsa+1<=k)
                    {
                        if(!dis[v[i][j]][ny+1][1])
                        {
                            if(!dis[v[i][j]][ny+1][0])dis[v[i][j]][ny+1][0]=nx;
                            else dis[v[i][j]][ny+1][1]=nx;
                            q.push((A){nx,ny+1,i});

                        }
                    }
                    lsa=j;
                    continue;
                }
                if(j-lsa+1<=k)
                {
                    if(!dis[v[i][j]][ny+1][1])
                    {
                        if(!dis[v[i][j]][ny+1][0])dis[v[i][j]][ny+1][0]=nx;
                        else dis[v[i][j]][ny+1][1]=nx;
                        q.push((A){v[i][j],ny+1,i});
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(dis,0,sizeof(dis));
        cin>>n>>k>>Q;
        maxn=-1;
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            for(int j=1;j<=t;j++)
            {
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        //for(int i=1;i<=10;i++)
        //{
        //    for(int j=1;j<=10;j++)cout<<dis[i][j][0]<<" ";
        //    cout<<endl;
        //}
        for(int i=1;i<=Q;i++)
        {
            scanf("%d%d",&tx[i],&ty[i]);
            maxn=max(maxn,tx[i]);
        }
        bfs();
        for(int i=1;i<=Q;i++)
        {
            if(dis[ty[i]][tx[i]][0])printf("1\n");
            else printf("0\n");
        }
        for(int i=1;i<=n;i++)v[i].clear();
    }
}
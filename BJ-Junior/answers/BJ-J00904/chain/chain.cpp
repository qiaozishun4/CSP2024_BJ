#include<bits/stdc++.h>
using namespace std;

int t;
int n,k,q;
int head[200010],nxt[200010],to[200010],w[200010],cnt;
int s[200010];
int r,c,flag;

void add(int u,int v,int d)
{
    nxt[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    w[cnt]=d;
}

void dfs(int u,int sum,int last)
{
    if(sum==r+1)
    {
        if(u==c)
            flag=1;
        return;
    }
    if(flag)
        return;
    for(int i=head[u];i!=0;i=nxt[i])
    {
        int v=to[i];
        if(w[i]!=last)
        {
            dfs(v,sum+1,w[i]);
        }
    }
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            int len;
            scanf("%d",&len);
            for(int j=1;j<=len;j++)
                scanf("%d",&s[i]);
            for(int j=1;j<=len;j++)
            {
                for(int l=1;l<k;l++)
                {
                    if(j+k<=len)
                        add(s[j],s[j+l],i);
                }
            }
        }
        while(q--)
        {
            scanf("%d%d",&r,&c);
            flag=0;
            dfs(1,1,0);
            if(flag)
                puts("1");
            else
                puts("0");
        }
        for(int i=1;i<=cnt;i++)
            head[i]=nxt[i]=to[i]=w[i]=0;
    }
    return 0 ;
}
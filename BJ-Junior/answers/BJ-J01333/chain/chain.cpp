#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int g[N][N],t,n,k;
int a[N],ans,q;
void dfs(int x,int e,int y,int fa)
{
    if(x==0)
    {
        if(e==y)
        {
            ans=1;
        }
        return;
    }
    if(ans)
    {
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(g[e][i])
        {
            dfs(x-1,i,y,e);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        memset(g,0,sizeof(g));
        while(n--)
        {
            int x;
            cin>>x;
            for(int i=0;i<x;i++)
            {
                cin>>a[i];
            }
            for(int i=0;i<x;i++)
            {
                for(int j=i+1;j<min(i+k-1,x);j++)
                {
                    g[a[i]][a[j]]++;
                }
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            ans=0;
            dfs(x,1,y,-1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}

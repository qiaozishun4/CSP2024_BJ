#include <bits/stdc++.h>//

using namespace std;
vector < pair<int,int> > g[100010];
int ll[200010];
int r,c;
bool ans=0;
void dfs(int step,int point,int color)
{
    if((r==step&&point==c)||ans==1)
    {
        ans=1;
        return ;
    }
    for(int i=0;i<g[point].size();i++)
    {
        if(g[point][i].second!=color) dfs(step+1,g[point][i].first,g[point][i].second);
        if(ans==1) return ;
    }
}
void solve()
{
    int l;
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>l;
        for(int j=1;j<=l;j++)
        {
            cin>>ll[j];
            for(int k=1;k<j;k++)
            {
                g[ll[k]].push_back( make_pair(ll[j],i) );//建边并记录来源
            }
        }
    }
    while(q--)
    {
        ans=0;
        cin>>r>>c;
        dfs(0,1,-1);//从1出发能否经过r步到达c
        cout<<ans<<endl;
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
        memset(ll,0,sizeof(ll));
        memset(g,0,sizeof(g));
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans=0;
int r[N];
bool vis[N];
void dfs(int x)
{
    vis[x]=true;
    for(int i=x+1;i<=n;i++)
    {
        if(r[i]>r[x]&&!vis[i])
        {
            dfs(i);
            break;
        }
    }
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    sort(r+1,r+n+1);
    if(r[n]==2)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(r[i]==1)cnt++;
        }
        if(cnt>n/2)cout<<cnt<<endl;
        else cout<<n-cnt<<endl;
        return 0;
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        dfs(i);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[200005];
int a[200005],n,cnt,c[200005];
ll ans=-1e18;
void dfs(int cur)
{
    if(cur>n)
    {
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            int pos=-1;
            for(int j=i-1;j>=1;j--)
            {
                if(vis[j]==vis[i])
                {
                    pos=j;
                    break;
                }
            }
            if(pos==-1)
            {
                c[i]=0;
            }
            else
            {
                if(a[pos]==a[i])
                {
                    c[i]=a[i];
                }
                else
                {
                    c[i]=0;
                }
            }
            res+=c[i];
        }
        ans=max(ans,res);
        return ;
    }
    cnt++;
    vis[cnt]=0;
    dfs(cur+1);
    vis[cnt]=1;
    dfs(cur+1);
    cnt--;
    return ;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cnt=0;
        ans=-1e18;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}

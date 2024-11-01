#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[200005],ans,last0,last1;
bool vis[200005];
void dfs(int step)
{
    if(step>n)
    {
        last0=-1;
        last1=-1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(a[i]==last0)sum+=a[i];
                last0=a[i];
            }
            else
            {
                if(a[i]==last1)sum+=a[i];
                last1=a[i];
            }
        }
        ans=max(ans,sum);
        return;
    }
    vis[step]=0;
    dfs(step+1);
    vis[step]=1;
    dfs(step+1);
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
        ans=0;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}

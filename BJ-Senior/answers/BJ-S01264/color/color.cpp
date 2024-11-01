
#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int num[100004];
int c[100004];
int vis[100004];
int ans=0,n;
void dfs(int k)
{
    if(k==n+1)
    {
        int cnt=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>0;j--)
            {
                if(vis[i]==vis[j])
                {
                    if(num[i]==num[j])
                    {
                        cnt+=num[j];
                    }
                    break;
                }
            }
        }
        ans=max(ans,cnt);
        return ;
    }
    vis[k]=0;
    dfs(k+1);
    vis[k]=1;
    dfs(k+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
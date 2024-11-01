#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200005],color[200005],ans;
void dfs(long long deep,long long yanse)
{
    color[deep]=yanse;
    if(deep==n)
    {
        long long res=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i-1;j>=1;j--)
            {
                if(color[i]==color[j]&&a[i]==a[j])
                {
                    res+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,res);
        return;
    }
    dfs(deep+1,0);
    dfs(deep+1,1);
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}

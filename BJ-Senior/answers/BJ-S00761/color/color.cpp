#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010];
long long ans;
void dfs(int step,int h_last,int l_last,long long sum)
{
    if(step>n)
    {
        ans=max(ans,sum);
        return;
    }
    if(a[step]==h_last)dfs(step+1,a[step],l_last,sum+a[step]);
    else dfs(step+1,a[step],l_last,sum);
    if(a[step]==l_last)dfs(step+1,h_last,a[step],sum+a[step]);
    else dfs(step+1,h_last,a[step],sum);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

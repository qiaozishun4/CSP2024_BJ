#include<bits/stdc++.h>
using namespace std;
int n,a[100],ans;
void dfs(int p,int l,int r,int sum)
{
    if(p==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    if(l!=0)
    {
        if(a[p]==a[l])dfs(p+1,p,r,sum+a[p]);
        else dfs(p+1,p,r,sum);
    }
    else dfs(p+1,p,r,sum);
    if(r!=0)
    {
        if(a[p]==a[r])dfs(p+1,l,p,sum+a[p]);
        else dfs(p+1,l,p,sum);
    }
    else dfs(p+1,l,p,sum);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        ans=0;
        dfs(1,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

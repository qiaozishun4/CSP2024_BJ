#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans,p[100010],c[100010];
void dfs(int x)
{
    if(x==n)
    {
        int cnt=0;
        for(int i=2;i<=n;i++)
        {
            c[i]=0;
            for(int j=i-1;j>=1;j--)
            {
                if(p[i]==p[j])
                {
                    if(a[i]==a[j])
                    c[i]=a[i];
                    break;
                }
            }
            cnt+=c[i];
        }
        ans=max(ans,cnt);
        return ;
    }
    for(int i=0;i<=1;i++)
    {
        p[x+1]=i;
        dfs(x+1);
    }
    return ;
}
void solve()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    cout<<ans<<endl;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

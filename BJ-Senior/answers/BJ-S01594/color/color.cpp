#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],n;
long long ans;
long long check()
{
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(b[j]==b[i])
            {
                if(a[i]==a[j]) sum+=a[i];
                break;
            }
        }
    }
    return sum;
}
void dfs(int x)
{
    if(x==n+1)
    {
        ans=max(ans,check());
        return;
    }
    b[x]=1;
    dfs(x+1);
    b[x]=2;
    dfs(x+1);
    b[x]=0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ans=0;
    dfs(1);
    cout<<ans<<endl;
}
int main()
{
    // freopen("color1.in","r",stdin);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
